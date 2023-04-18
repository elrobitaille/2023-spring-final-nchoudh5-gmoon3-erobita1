#include "bounds.h"

// TODO: implement member functions

// Default constructor 
Bounds::Bounds () { xmin = 0; xmax = 0; ymin = 0; ymax = 0; }; 

Bounds::Bounds(double xmin, double xmax, double ymin, double ymax) {
    this->xmin = xmin;
    this->xmax = xmax;
    this->ymin = ymin;
    this->ymax = ymax;
}

// Destructor 
Bounds::~Bounds () {};

void Bounds::set_xmin (double xmin) {this->xmin = xmin;};
void Bounds::set_xmax (double xmax) {this->xmax = xmax;};
void Bounds::set_ymin (double ymin) {this->ymin = ymin;};
void Bounds::set_ymax (double ymax) {this->ymax = ymax;};
