#ifndef __PHONG__
#define __PHONG__

#include "Material.h"
#include "../BRDFs/Lambertian.h"
#include "../BRDFs/GlossySpecular.h"

class Phong: public Material
{
    private :
        Lambertian*		ambient_brdf  ;
		Lambertian*		diffuse_brdf  ;
		GlossySpecular* specular_brdf ;

    public :
        Phong() ;

        Phong( const Phong& p ) ;

        virtual Material* clone() const ;

        Phong& operator= ( const Phong& rhs ) ;

        ~Phong() ;

        void    set_ka( const float ka ) ;

        void    set_kd( const float kd ) ;

        void    set_ks( const float ks ) ;

        void    set_cd( const RGBColor c ) ;

        void    set_cd( const float r , const float g , const float b ) ;

        void    set_exp( const float exp ) ;

        void    set_cs( const RGBColor & c ) ;

        void    set_cs( const float r , const float g , const float b ) ;

        void    set_cs( const float c ) ;

        virtual RGBColor shade( ShadeRec & s ) ;

        virtual RGBColor area_light_shade( ShadeRec& s ) ;
} ;

inline void	Phong::set_ka(const float ka) {         // �������BRDF�еķ�����
	ambient_brdf->set_kd( ka ) ;
}

inline void Phong::set_kd (const float kd) {        // ���������䲿�ֵķ�����
	diffuse_brdf->set_kd( kd ) ;
}

inline void Phong::set_cd(const RGBColor c) {       // ������������ɫ
	ambient_brdf->set_cd( c ) ;
	diffuse_brdf->set_cd( c ) ;
	specular_brdf->set_cs( c ) ;
}

inline void Phong :: set_cd( const float r , const float g , const float b )
{
    ambient_brdf->set_cd( r , g , b ) ;
	diffuse_brdf->set_cd( r , g , b ) ;
	specular_brdf->set_cs( r , g , b ) ;
}

inline void Phong :: set_ks( const float ks ) {     // ���þ��淴�䲿�ֵķ�����
    specular_brdf -> set_ks( ks ) ;
}

inline void Phong :: set_exp( const float exp ) {   // ����ָ��
    specular_brdf -> set_exp( exp ) ;
}

//�������þ��淴�䲿�ֵ���ɫ

inline void Phong :: set_cs( const RGBColor & c ) {
    specular_brdf -> set_cs( c ) ;
}

inline void Phong :: set_cs( const float r , const float g , float b ) {
    specular_brdf -> set_cs( r , g , b ) ;
}

inline void Phong :: set_cs( const float c ) {
    specular_brdf -> set_cs( c ) ;
}

#endif
