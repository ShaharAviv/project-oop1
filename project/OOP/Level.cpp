#include "Level.h"



Level::Level()
{
}


Level::~Level()
{
}






//// Item 31, More Effective C++, Scott Meyers
//
//class GameObject {
//	//...
//};
//
//class SpaceShip : public GameObject {
//	//...
//};
//
//class SpaceStation : public GameObject {
//	//...
//};
//
//class Asteroid : public GameObject {
//	//...
//};
//
//void checkForCollision(GameObject& object1, GameObject& object2)
//{
//	if (theyJustCollided(object1, object2)) {
//		processCollision(object1, object2);
//	}
//}
//
//// First solution:
//// Using Virtual Functions and RTTI
//
//class GameObject {
//public:
//	virtual void collide(GameObject& otherObject) = 0;
//	// ...
//};
//
//class SpaceShip : public GameObject {
//public:
//	virtual void collide(GameObject& otherObject);
//	// ...
//};
//
//// if we collide with an object of unknown type, we
//// throw an exception of this type:
//class CollisionWithUnknownObject {
//public:
//	CollisionWithUnknownObject(GameObject& whatWeHit);
//	// ...
//};
//
//void SpaceShip::collide(GameObject& otherObject)
//{
//	const type_info& objectType = typeid(otherObject);
//	if (objectType == typeid(SpaceShip)) {
//		SpaceShip& ship = static_cast<SpaceShip&>(otherObject);
//		// process a SpaceShip-SpaceShip collision;
//	}
//	else if (objectType == typeid(SpaceStation)) {
//		SpaceStation& station = static_cast<SpaceStation&>(otherObject);
//		// process a SpaceShip-SpaceStation collision;
//	}
//	else if (objectType == typeid(Asteroid)) {
//		Asteroid& asteroid = static_cast<Asteroid&>(otherObject);
//		// process a SpaceShip-Asteroid collision;
//	}
//	else {
//		throw CollisionWithUnknownObject(otherObject);
//	}
//}
//
//// Second solution:
//// Using Virtual Functions Only
//
//class SpaceShip; // forward declarations
//class SpaceStation;
//class Asteroid;
//
//class GameObject {
//public:
//	virtual void collide(GameObject& otherObject) = 0;
//	virtual void collide(SpaceShip& otherObject) = 0;
//	virtual void collide(SpaceStation& otherObject) = 0;
//	virtual void collide(Asteroid& otherobject) = 0;
//	// ...
//};
//
//class SpaceShip : public GameObject {
//public:
//	virtual void collide(GameObject& otherObject);
//	virtual void collide(SpaceShip& otherObject);
//	virtual void collide(SpaceStation& otherObject);
//	virtual void collide(Asteroid& otherobject);
//	// ...
//};
//
//void SpaceShip::collide(GameObject& otherObject) {
//	otherObject.collide(*this);
//}
//
//void SpaceShip::collide(SpaceShip& otherObject) {
//	// process a SpaceShip-SpaceShip collision;
//}
//void SpaceShip::collide(SpaceStation& otherObject) {
//	// process a SpaceShip-SpaceStation collision;
//}
//void SpaceShip::collide(Asteroid& otherObject) {
//	// process a SpaceShip-Asteroid collision;
//}
//
//// Third solution:
//// Using global table
//
//#include "SpaceShip.h"
//#include "SpaceStation.h"
//#include "Asteroid.h"
//namespace { // unnamed namespace — the standard way to make function "static"
//// primary collision-processing functions
//	void shipAsteroid(GameObject& spaceShip,
//		GameObject& asteroid);
//	void shipStation(GameObject& spaceShip,
//		GameObject& spaceStation);
//	void asteroidStation(GameObject& asteroid,
//		GameObject& spaceStation);
//	//...
//
//	// secondary collision-processing functions that just
//	// implement symmetry: swap the parameters and call a
//	// primary function
//	void asteroidShip(GameObject& asteroid,
//		GameObject& spaceShip)
//	{
//		shipAsteroid(spaceShip, asteroid);
//	}
//	void stationShip(GameObject& spaceStation,
//		GameObject& spaceShip)
//	{
//		shipStation(spaceShip, spaceStation);
//	}
//	void stationAsteroid(GameObject& spaceStation,
//		GameObject& asteroid)
//	{
//		asteroidStation(asteroid, spaceStation);
//	}
//	//...
//
//	typedef void(*HitFunctionPtr)(GameObject&, GameObject&);
//	typedef map< pair<string, string>, HitFunctionPtr > HitMap;
//
//	HitMap initializeCollisionMap()
//	{
//		HitMap phm;
//		phm[make_pair(typeid(SpaceShip).name(), typeid(Asteroid).name())] =
//			&shipAsteroid;
//		phm[make_pair(typeid(SpaceShip).name(), typeid(SpaceStation).name())] =
//			&shipStation;
//		//...
//		return phm;
//	}
//
//	HitFunctionPtr lookup(const string& class1,
//		const string& class2)
//	{
//		static HitMap collisionMap(initializeCollisionMap());
//		HitMap::iterator mapEntry = collisionMap.find(make_pair(class1, class2));
//		if (mapEntry == collisionMap.end())
//			return 0;
//		return (*mapEntry).second;
//	}
//
//} // end namespace
//
//void processCollision(GameObject& object1,
//	GameObject& object2)
//{
//	HitFunctionPtr phf = lookup(typeid(object1).name(),
//		typeid(object2).name());
//	if (phf)
//		phf(object1, object2);
//	else
//		throw UnknownCollision(object1, object2);
//}
//
//// In the book, there is even nicer solution for initializing the map in
//// a distributed way, instead of keep changing central initializeCollisionMap()
//// function, but this is enough for now.

