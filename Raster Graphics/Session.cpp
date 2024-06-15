#include "Session.h"

size_t Session::sessionsCount = 1;

Session::Session()
{
	ID = sessionsCount++;
}
void Session::addImage(const Polymorphic_ptr<Image>& image)
{
	imageCollection.pushBack(image);
}
void Session::addImage(Polymorphic_ptr<Image>&& image)
{
	imageCollection.pushBack(std::move(image));
}
void Session::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationExecutor.add(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationExecutor.add(std::move(transformation));
}
void Session::undo()
{
	transformationExecutor.undo();
}
void Session::save()
{
	//while (!transformationExecutor.isEmpty())
	//{
	//	transformationExecutor.
	//}
	
}
void Session::saveAs(const MyString& fileName)
{
	//transformationExecutor.executeAll();
	// TODO: set fileName to the first image 
}
void Session::close()
{
	reset();
}
void Session::printInfo() const
{
	printID();
	printImagesNames();
	printPendingTransformations();
}

// private 
void Session::printID() const
{
	std::cout << "Session ID = " << ID << std::endl;
}
void Session::printImagesNames() const
{
	std::cout << "Name of images in the session: ";
	// ...
	std::cout << '\n';
}
void Session::printPendingTransformations() const
{
	std::cout << "Pending transformations: ";
	// ...
}
void Session::reset()
{
	imageCollection.clear();
	transformationExecutor.clear();
}