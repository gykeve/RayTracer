#ifndef WROLD_H_INCLUDED
#define WROLD_H_INCLUDED

class GeometricObject;
class Paint;
class Tracer;

#include "ViewPlane.h"
#include "../Utilities/RGBColor.h"
#include "../Utilities/Ray.h"
#include "../Cameras/Camera.h"
#include "../Lights/Light.h"

using namespace std;

class World
{
    public :
        ViewPlane					vp ;                    // ��Ƭ
        Camera*                     camera_ptr ;            // ���
        RGBColor					background_color ;      // ������ɫ
        Tracer*				        tracer_ptr ;            // ������
        vector<GeometricObject*>	objects ;               // ����ļ���
        Paint* 				        paintArea ;             // ����
        Light*                      ambient_ptr ;           // ������
        vector<Light*>              lights ;                // ��Դ����

    public :
        World() ;

        ~World() ;

        void  add_object( GeometricObject* object_ptr ) ;

        void  build() ;                                     // ��������

        void  render_sence() const ;

        RGBColor max_to_one    ( const RGBColor & c ) const ;

		RGBColor clamp_to_color( const RGBColor & c ) const ;

		void  display_pixel(const int row, const int column, const RGBColor& pixel_color) const;

        ShadeRec hit_bare_bones_objects ( const Ray & ray ) ;

        void  set_camera( Camera* _camera );

        void  set_ambient_light( Light* a_ptr ) ;

        void  add_light( Light* light_ptr ) ;

        //void  open_window( const int hres , const int vres ) const ;

        ShadeRec hit_objects( const Ray& ray , float & tmin ) ;

        ShadeRec hit_objects( const Ray& ray ) ;

    private :
        void delete_objects() ;
} ;

inline void World :: add_object( GeometricObject* object_ptr ){
    objects.push_back( object_ptr ) ;
}

inline void World :: add_light( Light* light_ptr ) {
    lights.push_back( light_ptr ) ;
}

inline void World :: set_camera( Camera* _camera ) {
    camera_ptr = _camera ;
}

inline void World :: set_ambient_light( Light* a_ptr ) {
    ambient_ptr = a_ptr ;
}

#endif
