#ifndef BOUNDS_H
#define BOUNDS_H

class Bounds {
private:
  // TODO: add fields
  double xmin;
  double xmax;
  double ymin;
  double ymax;

public:
  // TODO: add member functions

  // Define default and non-default constructor, and destructor 
  Bounds();
  Bounds(double xmin, double xmax, double ymin, double ymax);
  ~Bounds();

  // Define setters and getters for the fields
  double get_xmin() const;
  double get_xmax() const;
  double get_ymin() const;
  double get_ymax() const;

  void set_xmin(double xmin);
  void set_xmax(double xmax);
  void set_ymin(double ymin);
  void set_ymax(double ymax);

  double get_width() const;
  double get_height() const;

  double set_width(double width);
  double set_height(double height);

  // Returns if the value is within the bounds as it should be
  bool contains(double x, double y) const {
    return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
  }
  
};

#endif // BOUNDS_H
