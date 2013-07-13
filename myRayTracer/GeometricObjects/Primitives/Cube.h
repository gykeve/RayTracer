#ifndef _CUBE_H
#define _CUBE_H
#include <vector>
#include "../GeometricObject.h"
#include "Rectangle.h"
class Cube: public GeometricObject{
private :
	vector<Rectangles*> rectangles ;
	Point3D leftbuttomback ;//leftbuttomback���������һ������,top��right��front�ֱ����Ըõ�Ϊ���ķ�������ͬʱ����������ı߳�
	Vector3D top;    //ע���ʱ��top��right��ɵ��淨������top*right  ������ָ�����������
	Vector3D right;  //ע���ʱ��right��front��ɵ��淨������right*front
	Vector3D front;  //ע���ʱ��front��top��ɵ��淨������front*top

public :
	Cube();
	Cube(const Point3D& _leftbuttomback,const Vector3D& _top,const Vector3D& _right,const Vector3D& _front );
	virtual Cube*
	clone(void) const;

	Cube(const Cube& r);

	virtual
	~Cube(void);

	Cube& operator= (const Cube& rhs);
	virtual void
	set_material(Material* mPtr) ;

	virtual bool
    hit( const Ray& ray, double& tmin, ShadeRec& sr ) const ;

    virtual bool
    shadow_hit( const Ray& ray , float &tmin )const ;

};

#endif
