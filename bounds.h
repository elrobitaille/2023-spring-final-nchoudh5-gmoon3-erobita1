#ifndef BOUNDS_H
#define BOUNDS_H

class Bounds {
private:
  // Defining the bounds of the plot
  double xmin;
  double xmax;
  double ymin;
  double ymax;

public:
  // Define default and non-default constructor, and destructor 
  Bounds();
  Bounds(double xmin, double xmax, double ymin, double ymax);
  ~Bounds();

  // Define setters and getters for the x and y positions
  double get_xmin() const {return xmin;};
  double get_xmax() const {return xmax;};
  double get_ymin() const {return ymin;};
  double get_ymax() const {return ymax;};

  void set_xmin(double xmin);
  void set_xmax(double xmax);
  void set_ymin(double ymin);
  void set_ymax(double ymax);

  // Define setters and getters for the width and height
  double get_width() const {return xmax - xmin;};
  double get_height() const {return ymax - ymin;};

  double set_width(double width);
  double set_height(double height);

  // Returns if the value is within the bounds as it should be
  bool contains(double x, double y) const {
    return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
  }
  
};

#endif // BOUNDS_H
