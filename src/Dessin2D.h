#pragma once
#include<vector>
#include "ofMain.h"


enum class Primitive2D { point, line, rectangle, ellipse, triangle, image };
enum class CursorType { point, cross, rectangle, ellipse, x_shape };                                        

struct ShapeProperties {
	Primitive2D type;


	float x1;
	float y1;

	float x2;
	float y2;

	float stroke_width;

	float radius;
	float height;
	float width;

	int stroke_r;
	int stroke_g;
	int stroke_b;
	int stroke_a;

	int fill_r;
	int fill_g;
	int fill_b;
	int fill_a;

	ofImage image;
	std::string path;
};


class Dessin2D
{
public:
	std::vector<ShapeProperties> shapes;
	std::vector<ShapeProperties> backup;
	Primitive2D shape_mode = Primitive2D::rectangle;

	ofColor fill_color;
	ofColor stroke_color;
	ofColor cursor_press_color = ofColor(120, 35, 50, 255);

	ofImage bg_image;



	float stroke_width;

	int mouse_press_x = 0;
	int mouse_press_y = 0;

	int mouse_current_x = 0;
	int mouse_current_y = 0;

	int img_start_x;
	int img_start_y;
	int img_end_x;
	int img_end_y;

	bool mouse_press = false;

	void add_shape(Primitive2D prim);
	void clear_contents();
	void undo();
	void redo();

	void draw() const;

	void add_image();
	void draw_outline() const;
	void draw_cursor() const;

	void draw_cursor_line(int x, int y) const;
	void draw_cursor_point(int x, int y) const;
	void draw_cursor_ellipse(int x, int y) const;
	void draw_cursor_rectangle(int x, int y) const;
	void draw_cursor_x(int x, int y) const;
	void draw_bg_image() const;
	void add_bg_image();

	void point(float x, float y, float radius) const;
	void line(float x1, float y1, float x2, float y2) const;
	void rectangle(float x1, float y1, float x2, float y2) const;
	void ellipse(float x1, float y1, float x2, float y2) const;
	void triangle(float x1, float y1, float w, float ) const;
};

