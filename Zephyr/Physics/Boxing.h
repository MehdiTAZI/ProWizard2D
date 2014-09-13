#ifndef BONDINGBOX_H
#define BONDINGBOX_H
namespace ProWiz
{
	namespace Physics
	{
		template<typename T>
		class Boxing
		{
		public : 
			
			void CircleToBox(ProWiz::GraphicsManager::Drawing::GeometryObjects::Circle<T> Circle,ProWiz::GraphicsManager::Drawing::GeometryObjects::Rectangle<T>*BoxedCircle)
			{
				BoxedCircle->Position=(Circle.Position-Circle.Radius);
				BoxedCircle->Dimension=(Circle.Radius*2);
			}
			//Polygon quad strip trigangle triangel strip
			void TriangeToBox(ProWiz::GraphicsManager::Drawing::GeometryObjects::Triangle<T> Triange,ProWiz::GraphicsManager::Drawing::GeometryObjects::Rectangle<T>*BoxedTriangle)
			{
				BoxedTriangle->Position = Triange.Point2;
				BoxedTriangle->Dimension.Height=(Triange.Point1.Y-Triange.Point2.Y);
				BoxedTriangle->Dimension.Width=(Triange.Point3.X-Triange.Point2.X);
			}

		};
	}
}
#endif