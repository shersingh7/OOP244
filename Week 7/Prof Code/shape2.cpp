// A demo on inheritance (i.e. an inheritance hierarchy)
// How are the constructors and destructos invoked?

#include <iostream>
using namespace std;

const double PI=3.1416;

// base class
class Shape {
    protected:             // accessible to derived classes
      int side1;

   public:
      Shape(int size);     // base-class constructor
      double calcArea() const;
      void display()const;
      ~Shape();            // base-class destructor
};


// derived class
class Circle: public Shape {
			      // one inherited data member (protected)
			      // no NEW data member
   public:
      Circle(int r);          // NEW derived-class constructor; r: radius
      double calcArea()const; // shadowing: redefine the base-class calcArea()
      ~Circle();              // NEW derived-class destructor
};

// derived class
class Rectangle: public Shape {
				    // one inherited data member (protected)
    protected:
       int side2;                   // one NEW data member(protected)
  
    public:
       Rectangle(int s1, int s2);   // NEW derived-class constructor

       double calcArea() const;     // shadowing: redefine calcArea()
       ~Rectangle();                // NEW derived-classdestructor
};


// derived class
class Square: public Rectangle {
	   
				 // two inherited data members(protected)
    public:
       Square(int s);            // NEW constructor
       double calcArea() const;  // Question: Is this necessary?!
       ~Square();                // NEW destructor
};


// a driver program that uses the classes
//   - the order of invoking the constructors and destructors
int main(void)
{
   Shape     aShape(1000);

   Rectangle rectangle(9,3);
   Circle    circle(6);
   Square    square(10);

   cout << "... Four objects will go out of scope soon!\n";

   return 0;
}


/* ******* Class Hierarchy Implementation ******* */
Shape::Shape(int n) { 

  side1 = n;
  cout << "\n\t a shape(" << side1 << ") is created\n"; 
}

Shape::~Shape() { cout << "~Shape() invoked!\n"; } 

double Shape::calcArea() const
{ return 0.0; }

void Shape::display() const {
   cout << "I'm a shape " 
	<< "(" << side1 << " units)!" << endl;
}

// base-class constructor used in an initialisation list
Circle::Circle(int r) : Shape(r)
{                                      
	// side1: inherited data member has been initialized by the base-class constructor
		      
	   cout << "\t # a circle of radius " << side1
		<< " has been created #\n";
	
 }

// shadowing: redefinition of  the member function CalcArea() in the base class
double Circle::calcArea() const
{       // side1: inherited data member; the radius of a circle

	return (PI * static_cast<double>(side1) 
		   * static_cast<double>(side1) ); 
}
 
Circle::~Circle() { cout << "~Circle() invoked!\n"; }


// initialisation list; base-class constructor: Shape(s1)
Rectangle::Rectangle(int s1, int s2) : Shape(s1)
{                                   // side1: inherited data member
	side2 = s2;                 // side2: new data member

	cout << "\t + a rectangle(" << side1 << "x" << side2
	     << ") been created +" << endl;
 
}

// shadowing: redefinition of  the member function CalcArea in the base class
double Rectangle::calcArea() const
{
	return ( static_cast<double>(side1 * side2) );
}
  
Rectangle::~Rectangle() { cout << "~Rectangle() invoked!\n"; }

// initialisation list; base-class constructor: Rectangle(---)
Square::Square(int size) : Rectangle(size, size)
{                                // side1, side2: two inherited data members

   cout << "\t *** a square(" << side1 << "x" << side2
	<< ") has been created ***\n" << endl;    
}
	 
double Square::calcArea() const
{
      return static_cast<double>(side1*side1);

      //return Rectangle::CalcArea();
}
     
Square::~Square() { cout << "~Square() invoked!\n"; }