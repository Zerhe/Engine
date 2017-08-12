#include "Graphics.h"

bool Graphics::Initialize(HWND wndHandle, int width, int height) {
	pD3D = NULL;
	pd3dDevice = NULL;
	// Create the DirectX object
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}

	D3DDISPLAYMODE* mode = new D3DDISPLAYMODE();

	pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, mode);

	// Fill the presentation parameters structure
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = mode->Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = height;
	d3dpp.BackBufferWidth = width;
	d3dpp.hDeviceWindow = wndHandle;
	// Create a default DirectX device
	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_REF,
		wndHandle,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&pd3dDevice)))
	{
		return false;
	}
	vertexBufferShape.Create(pd3dDevice);
	vertexBufferSprite.Create(pd3dDevice);

	return true;
}
void Graphics::Shutdown() {
	// Release the device and the Direct3D object
	if (pd3dDevice != NULL)
		pd3dDevice->Release();
	if (pD3D != NULL)
		pD3D->Release();
	vertexBufferShape.Release();
	vertexBufferSprite.Release();
}
void Graphics::Clear(){
	pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, _clearColor, 1.0f, 0);
}
void Graphics::Begin() {
	pd3dDevice->BeginScene();
}
void Graphics::End() {
	pd3dDevice->EndScene();
}
void Graphics::Present() {
	if (pd3dDevice)
		pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
void Graphics::SetTransformCamera(D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix)
{
	pd3dDevice->SetTransform(state, matrix);
}
bool Graphics::SetupScene()
{
	HRESULT hRes;

	// Obtengo el viewport
	hRes = pd3dDevice->GetViewport(&_viewport);

	if (FAILED(hRes)) {
		return false;
	}

	// Registro el viewport obtenido
	//FileLog::Write("Viewport {x=%d, y=%d, w=%d, h=%d}\n", _viewport.X, _viewport.Y, _viewport.Width, _viewport.Height);

	// -----------------------------------------------------------------------
	// Fijo la Matriz del Mundo, que es la que transforma de coordenadas
	// locales de los objetos a la de mundo
	// -----------------------------------------------------------------------
	D3DXMATRIX d3dmat;
	D3DXMatrixIdentity(&d3dmat);
	pd3dDevice->SetTransform(D3DTS_WORLD, &d3dmat);

	// -----------------------------------------------------------------------
	// Fijo la matriz de vista, que es la transforma a todos los vértices
	// para cambiar el punto de visión de la escena
	// -----------------------------------------------------------------------
	
	D3DXVECTOR3 eyePos(_viewport.Width / 2.0f, _viewport.Height / 2.0f, -5.0f);
	D3DXVECTOR3 lookPos(_viewport.Width / 2.0f, _viewport.Height / 2.0f, 0.0f);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&d3dmat, &eyePos, &lookPos, &upVec);
	pd3dDevice->SetTransform(D3DTS_VIEW, &d3dmat);

	// -----------------------------------------------------------------------
	// Seteo la Matriz de Proyección, que es la que transforma nuestro mundo
	// 3d en un viewport 2d que es mostrado en pantalla
	// -----------------------------------------------------------------------
	D3DXMATRIX mProjectionMatrix;
	float fAspectRatio = (float)_viewport.Width / _viewport.Height;

	//D3DXMatrixPerspectiveFovLH(&mProjectionMatrix, D3DX_PI/4.0f, fAspectRatio, 1.0f, 1000.0f);
	D3DXMatrixOrthoLH(&mProjectionMatrix, (float)_viewport.Width, (float)_viewport.Height, -25.0f, 25.0f);
	hRes = pd3dDevice->SetTransform(D3DTS_PROJECTION, &mProjectionMatrix);

	if (FAILED(hRes)) {
		return false;
	}

	//pd3dDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(80, 80, 80));			//ambient light
	pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	//pd3dDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_FLAT);
	//pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // D3DCULL_CCW


															// TEMPORAL
	pd3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	pd3dDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pd3dDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// Fijo valores por defecto para operaciones con el canal alpha
	pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// Deshabilito los speculars
	pd3dDevice->SetRenderState(D3DRS_SPECULARENABLE, FALSE);

	// Deshabilito el stencil
	pd3dDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);

	return true;
}
void Graphics::DrawShape(CUSTOMVERTEX* vertices, int cantVert)
{
	vertexBufferShape.Bind();
	vertexBufferShape.Draw( vertices, D3DPT_TRIANGLELIST, cantVert);
}
void Graphics::DrawSprite(CUSTOMVERTEXTEXTURE* vertices, int cantVert)
{
	vertexBufferSprite.Bind();
	vertexBufferSprite.Draw( vertices, D3DPT_TRIANGLESTRIP, cantVert);
}
void Graphics::LoadIdentity()
{
	D3DXMATRIX matIdentity;

	D3DXMatrixIdentity(&matIdentity);
	pd3dDevice->SetTransform(D3DTS_WORLDMATRIX(0), &matIdentity);
}
void Graphics::Translate(float x, float y, float z) 
{
	D3DXMATRIX matTranslate;

	D3DXMatrixTranslation(&matTranslate, x, y, z);
	pd3dDevice->MultiplyTransform(D3DTS_WORLDMATRIX(0), &matTranslate);

}
void Graphics::RotationZ(float angle) 
{
	D3DXMATRIX matRotate;

	D3DXMatrixRotationZ(&matRotate, D3DXToRadian(angle));
	pd3dDevice->MultiplyTransform(D3DTS_WORLDMATRIX(0), &matRotate);
}
void Graphics::Scaling(float sx, float sy, float sz) 
{
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, sx, sy, sz);
	pd3dDevice->MultiplyTransform(D3DTS_WORLDMATRIX(0), &matScale);
}
LPDIRECT3DTEXTURE9 Graphics::LoadTexture(LPCWSTR stringTexture)
{
	LPDIRECT3DTEXTURE9 _texture = NULL; 
										 
	D3DXCreateTextureFromFile(pd3dDevice, stringTexture, &_texture);

	return _texture;
}
void Graphics::BindTexture(LPDIRECT3DTEXTURE9 textura) 
{
	pd3dDevice->SetTexture(0, textura);
}

