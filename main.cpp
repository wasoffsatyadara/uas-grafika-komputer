/**************************
 * Includes
 *
 **************************/

#include <stdlib.h>
#include <windows.h>		
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "glut.h"
#include "glaux.h"

/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

GLfloat	xrot;				// deklarasi rotasi x 
GLfloat	yrot;				// deklarasi rotasi y
GLfloat	zrot;				// deklarasi rotasi z

GLuint	texture[1];			// digunakan untuk menampung 1 gambar

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	

AUX_RGBImageRec *LoadBMP(char *Filename)				// fungsi menampilkan gambar
{
	FILE *File=NULL;									

	if (!Filename)										
	{
		return NULL;								
	}

	File=fopen(Filename,"r");							// digunakan untuk membaca file 

	if (File)											
	{
		fclose(File);									
		return auxDIBImageLoad(Filename);				// jika gambar ada tampilkan gambar
	}

	return NULL;										
}

int LoadGLTextures()									// fungsi menampilkan gambar dan  Convert ke Textures
{
	int Status=FALSE;									

	AUX_RGBImageRec *TextureImage[10];				// membuat temporary untuk menyimpan gambar

	memset(TextureImage,0,sizeof(void *)*1);           	

	if (TextureImage[0]=LoadBMP("GAMBAR.bmp"))  //pengambilan data gambar (256X256)
	{
		Status=TRUE;									

		glGenTextures(1, &texture[0]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[1]=LoadBMP("JamDinding.bmp"))  //pengambilan data gambar (256X256)
	{
		Status=TRUE;									

		glGenTextures(1, &texture[1]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[2]=LoadBMP("ac.bmp"))  //pengambilan data gambar (256X256)
	{
		Status=TRUE;									

		glGenTextures(1, &texture[2]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[2]->sizeX, TextureImage[2]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[2]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[3]=LoadBMP("asset/lantai-1.bmp"))  //pengambilan data gambar untuk lantai
	{
		Status=TRUE;									

		glGenTextures(1, &texture[2]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[3]->sizeX, TextureImage[3]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[3]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[4]=LoadBMP("asset/dinding-1.bmp"))  //pengambilan data gambar untuk dinding kiri
	{
		Status=TRUE;									

		glGenTextures(1, &texture[4]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[4]->sizeX, TextureImage[4]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[4]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[5]=LoadBMP("asset/dinding-2.bmp"))  //pengambilan data gambar untuk dinding kiri
	{
		Status=TRUE;									

		glGenTextures(1, &texture[5]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[5]->sizeX, TextureImage[5]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[5]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[6]=LoadBMP("asset/dinding-3.bmp"))  //pengambilan data gambar untuk dinding kiri
	{
		Status=TRUE;									

		glGenTextures(1, &texture[6]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[6]->sizeX, TextureImage[6]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[6]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	
	if (TextureImage[7]=LoadBMP("Kelompok.bmp"))  //pengambilan data gambar untuk dinding kiri
	{
		Status=TRUE;									

		glGenTextures(1, &texture[7]);					

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[7]->sizeX, TextureImage[7]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[7]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
}

void kubusNormal()	{
	glBegin(GL_QUADS);        
        // Muka depan
        glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal menuju Anda
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 1 (depan)
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 2 (depan)
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (depan)
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 4 (depan)
    
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
	
    	// Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
}

void kubusRuangan()	{
	
    // Untuk bahan objek kubus sisi belakang
    GLfloat bahan_ambient0[]= {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_diffuse0[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_specular0[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_shininess0[] = {10.0f};
    // Untuk bahan objek kubus sisi kiri
     GLfloat bahan_ambient1[]= {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_diffuse1[] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_specular1[] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_shininess1[] = {10.0f};
    // Untuk bahan objek kubus sisi kanan
    GLfloat bahan_ambient2[]= {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_diffuse2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_specular2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_shininess2[] = {10.0f};
    // Untuk bahan objek kubus sisi atas
    GLfloat bahan_ambient3[]= {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_diffuse3[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_specular3[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_shininess3[] = {10.0f};
	glBegin(GL_QUADS);        
		glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient0);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse0);
        glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular0);
        glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess0);
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse1);
        glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular1);
        glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess1);
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	    
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse2);
        glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular2);
        glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess2);
    	// Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
}

void kubusTekstur()
{
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glEnable(GL_TEXTURE_2D);	
        glBegin(GL_QUADS);        
        // Muka depan
        glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal menuju Anda
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 1 (depan)
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 2 (depan)
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (depan)
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 4 (depan)
    
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
	
    	// Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
        // Akhir kode yang diambil dari bukunya Suyoto
        //******************************************************
}

void kubusJamTekstur()
{   	
        glBindTexture(GL_TEXTURE_2D, texture[1]); //menampilkan citra
        glEnable(GL_TEXTURE_2D);	
        glBegin(GL_QUADS);        
        // Muka depan
        glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal menuju Anda
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 1 (depan)
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 2 (depan)
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (depan)
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 4 (depan)
    
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
	
    	// Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
        // Akhir kode yang diambil dari bukunya Suyoto
        //******************************************************
}

void kubusAcTekstur()
{   	
        glBindTexture(GL_TEXTURE_2D, texture[2]); //menampilkan citra
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        // Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
		glEnd();
	    glDisable(GL_TEXTURE_2D);
    	
        glBegin(GL_QUADS);
        
        // Muka depan
        glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal menuju Anda
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 1 (depan)
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 2 (depan)
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (depan)
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 4 (depan)
	    
	
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
        // Akhir kode yang diambil dari bukunya Suyoto
        //******************************************************
}

void kubusFiguraKananTekstur()
{   	        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[7]); //menampilkan citra
		glBegin(GL_QUADS);
        // Muka kanan
    	glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
		glEnd();
	    glDisable(GL_TEXTURE_2D);
    	
        glBegin(GL_QUADS);
        
        // Muka depan
        glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal menuju Anda
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 1 (depan)
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 2 (depan)
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (depan)
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 4 (depan)
	    
	
        // Muka belakang		
       	glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal meninggalKan Anda
       	glTexCoord2f(1.0f, 0.0f);
       	glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (belakang)
       	glTexCoord2f(1.0f, 1.0f);
       	glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 2 (belakang)
       	glTexCoord2f(0.0f, 1.0f);
       	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 3 (belakang)
       	glTexCoord2f(0.0f, 0.0f);
       	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 4 (belakang)
	
	    // Muka Atas	
	    glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal berarah atas
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 1 (atas)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 2 (atas)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (atas)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 4 (atas)
	
	    // Muka bawah
	    glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal berarah bawah
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (bawah)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 2 (bawah)
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 3 (bawah)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 4 (bawah)
   	
	    // Muka kiri
	    glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal berarah ke kiri
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);	// Titik 1 (kiri)
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f,  1.0f);	// Titik 2 (kiri)
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f,  1.0f);	// Titik 3 (kiri)
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex3f(-1.0f,  1.0f, -1.0f);	// Titik 4 (kiri)
	
	    glEnd();
        // Akhir kode yang diambil dari bukunya Suyoto
        //******************************************************
}

void FotoKelompokKanan()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]); //menampilkan citra 
	glBegin(GL_QUADS);        
        glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal berarah ke kanan
    	glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);	// Titik 1 (kanan)
    	glTexCoord2f(1.0f, 1.0f);  	glVertex3f( 1.0f,  1.0f, -1.0f);	// Titik 2 (kanan)
    	glTexCoord2f(0.0f, 1.0f);  	glVertex3f( 1.0f,  1.0f,  1.0f);	// Titik 3 (kanan)
    	glTexCoord2f(0.0f, 0.0f);   glVertex3f( 1.0f, -1.0f,  1.0f);	// Titik 4 (kanan)
   	glEnd();
   	glDisable(GL_TEXTURE_2D);
}

//******************************************************
// Awal kode yang diambil dari bukunya Suyoto
void Inisialisasi(int lebar, int tinggi)
{
	
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClearAccum(0.0, 0.0, 0.0, 0.0);
  	glViewport (0, 0, lebar, tinggi); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluPerspective(60.0, (GLfloat) lebar/(GLfloat) tinggi, 1.0, 20.0);
	glMatrixMode (GL_MODELVIEW);
	LoadGLTextures();

	// hidupkan pencahayaan
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    //glShadeModel (GL_FLAT);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}
// Akhir kode yang diambil dari bukunya Suyoto
//******************************************************

/**************************
 * WinMain
 *
 **************************/

int WINAPI 
WinMain (HINSTANCE hInstance,
         HINSTANCE hPrevInstance,
         LPSTR lpCmdLine,
         int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    // Untuk bahan objek teko
    GLfloat bahan_ambient0[]= {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_diffuse0[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_specular0[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat bahan_shininess0[] = {10.0f};
	
	// Untuk bahan objek torus
    GLfloat bahan_ambient1[]= {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_diffuse1[] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_specular1[] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat bahan_shininess1[] = {10.0f};
	
	// Untuk bahan objek bola
    GLfloat bahan_ambient2[]= {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_diffuse2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_specular2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat bahan_shininess2[] = {10.0f};
	
    // Untuk bahan objek kubus
    GLfloat bahan_ambient3[]= {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_diffuse3[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_specular3[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat bahan_shininess3[] = {10.0f};


    // Untuk Pencahayaan
	GLfloat IntensitasCahaya0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat PosisiCahaya0[]={0.0f,6.0f,5.0f, 1.0f};
	GLfloat PosisiCahaya1[]={-10.0f,0.0f,-10.0f, 1.0f};
	GLfloat PosisiCahaya2[]={15.0f,10.0f,-9.0f, 0.0f};

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "TF-UAJY";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "TF-UAJY", "Teko, Torus, Bola dan Kubus dengan Citra [8240 & 8332]", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 1024, 768,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);
    
    
    //******************************************************
    // Awal kode yang diambil dari bukunya Suyoto
    Inisialisasi(1024, 768);
    // Akhir kode yang diambil dari bukunya Suyoto
    //******************************************************
    
    
    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
            //******************************************************
            // Awal kode yang diambil dari bukunya Suyoto
            //glColor3f (0, 0, 1);
            
            //bahan untuk teko
            glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient0);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse0);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular0);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess0);		
           	glLightfv(GL_LIGHT0, GL_DIFFUSE, IntensitasCahaya0);
           	glLightfv(GL_LIGHT0, GL_POSITION, PosisiCahaya0);
           	
        	glPushMatrix( );
        		glTranslatef (-0.3, -2.2f, -6.0f);
        		glScalef(0.3f, 0.3f, 0.3f);
                glRotatef(yrot+20,0.0f,1.0f,0.0f);
        		glutSolidTeapot(0.8f );
        	glPopMatrix( );
        	
        	//bahan untuk torus
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient1);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse1);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular1);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess1);	
        	//glutSolidTorus	(	 innerRadius , outerRadius , nsides , rings )
        	glPushMatrix( );
                glTranslatef (0.4f, -2.2f, -6.0f);
                glScalef(0.3f, 0.3f, 0.3f);
                glRotatef(yrot,0.0f,1.0f,0.0f);
        		glutSolidTorus(0.3f, 0.5f, 200, 200);
        	glPopMatrix( );
        	
        	//bahan untuk bola
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse1);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular2);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess1);	
        	
        	//glutSolidSphere	(	 radius , slices , stacks )
        	glPushMatrix( );
                glTranslatef (-1.0f, -2.2f, -6.0f);
                glScalef(0.2f, 0.2f, 0.2f);
        		glRotatef (90, 1, 0, 0);
        		glutSolidSphere(1.0f, 200, 200);
        	glPopMatrix( );
        	
        	//bahan untuk kubus
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);	
           	
        	//kubusTekstur()
        	glPushMatrix( );
                glTranslatef (1.1f, -2.2f, -6.0f);
                glScalef(0.2f, 0.2f, 0.2f);
        		//glRotatef(180,1.0f,0.0f,0.0f);
                glRotatef(yrot,0.0f,1.0f,0.0f);
                //glRotatef(zrot,0.0f,0.0f,1.0f);
        		kubusTekstur();
        		
        	glPopMatrix( );
        	
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient0);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse2);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular0);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess0);		
        	
        	glPushMatrix();
        		glTranslatef (0.0f, -2.8f, -6.7f);
                glScalef(1.7f, 0.2f, 1.0f);
				glRotatef (43, 0, 1, 0);
        		       	
        		kubusNormal();
        	glPopMatrix();
        	/*
        	
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);
           	glLightfv(GL_LIGHT0, GL_DIFFUSE, IntensitasCahaya0);
           	glLightfv(GL_LIGHT0, GL_POSITION, PosisiCahaya2);
           	
        	glPushMatrix();	
        		glTranslatef(0.0f, 0.5f, -10.0f);
        		glRotatef(0.0, 0.0f, 1.0f ,0.0f);
				glScalef(6.0f, 4.0f, 5.0f);
        		kubusRuangan();
        	glPopMatrix();
        	*/
        	//JAM
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);	
           	glLightfv(GL_LIGHT0, GL_DIFFUSE, IntensitasCahaya0);
           	glLightfv(GL_LIGHT0, GL_POSITION, PosisiCahaya0);
           		
        	glPushMatrix( );
                
                glTranslatef (0.0f, 3.5f, -14.99f);
				glScalef(0.7f, 0.7f, 0.f);
        		//glRotatef(180,1.0f,0.0f,0.0f);
                //glRotatef(zrot,0.0f,0.0f,1.0f);
        		kubusJamTekstur();
        	glPopMatrix( );
        	
        	//AC 1
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);
           	
        	glPushMatrix( );
                glTranslatef (-5.95f, 3.0f, -11.0f);
				glScalef(0.4f, 0.7f, 2.3f);
				glRotatef (0.0f, 0.0f, 1.0f, 0.0f);
        		kubusAcTekstur();
        	glPopMatrix( );
        	
        	//AC 2
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);
           	
        	glPushMatrix( );
                glTranslatef (5.95f, 3.0f, -11.0f);
				glScalef(0.4f, 0.7f, 2.3f);
				glRotatef (180.0f, 0.0f, 1.0f, 0.0f);
        		kubusAcTekstur();
        	glPopMatrix( );
        	
        	//Foto Kanan
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);
           	glLightfv(GL_LIGHT0, GL_DIFFUSE, IntensitasCahaya0);
           	glLightfv(GL_LIGHT0, GL_POSITION, PosisiCahaya1);
        	glPushMatrix( );
                glTranslatef (5.95f, 1.0f, -11.0f);
				glScalef(0.05f, 1.0f, -2.0f);
				glRotatef (180.0f, 0.0f, 1.0f, 0.0f);
        		kubusFiguraKananTekstur();
        	glPopMatrix( );
        	
			/*        	
        	//Wallpaper KANAN
        	glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient3);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,bahan_diffuse3);
            glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
           	glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);
           	glLightfv(GL_LIGHT0, GL_DIFFUSE, IntensitasCahaya0);
           	glLightfv(GL_LIGHT0, GL_POSITION, PosisiCahaya2);
           	
        	glPushMatrix();
	        		glTranslatef(0.0f, 0.5f, -11.0f);
	        		glRotatef(0.0, 0.0f, 1.0f ,0.0f);
					glScalef(6.0f, 4.0f, -4.0f);
					FotoKelompokKanan();
			glPopMatrix();
			*/
				
        	xrot+=0.3f;   //Mengatur arah putaran object
	        yrot+=0.2f;   //Mengatur arah putaran object
	        zrot+=0.4f;   //Mengatur arah putaran object
        	
        	
            // Akhir kode yang diambil dari bukunya Suyoto
            //******************************************************
            
            SwapBuffers (hDC);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK 
WndProc (HWND hWnd, UINT message,
         WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void
EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void
DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
