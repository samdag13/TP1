#include "Dessin2D.h"

void draw(){
}

void Dessin2D::add_shape(Primitive2D prim) {
	ShapeProperties shape;
	shape.type = prim;

	shape.x1 = mouse_press_x;
	shape.y1 = mouse_press_y;
	shape.x2 = mouse_current_x;
	shape.y2 = mouse_current_y;

	shape.fill_r = fill_color.r;
	shape.fill_g = fill_color.g;
	shape.fill_b = fill_color.b;
	shape.fill_a = fill_color.a;

	shape.stroke_r = stroke_color.r;
	shape.stroke_g = stroke_color.g;
	shape.stroke_b = stroke_color.b;
	shape.stroke_a = stroke_color.a;

	shape.stroke_width = stroke_width;

	shape.width = mouse_current_x - mouse_press_x;
	shape.height = mouse_current_y - mouse_press_y;
	shape.radius = sqrt(pow(shape.height, 2) + pow(shape.width, 2)) / 2.0f;

	shapes.push_back(shape);
}

void Dessin2D::clear_shapes() {
	shapes.clear();
}

void Dessin2D::draw() {

	for (int i = 0; i < shapes.size(); i++) {



		switch (shapes[i].type)
		{
		case Primitive2D::point:
			ofFill();
			ofSetLineWidth(0);
			ofSetCircleResolution(100);
			ofSetColor(
				shapes[i].fill_r,
				shapes[i].fill_g,
				shapes[i].fill_b,
				shapes[i].fill_a);
			point(
				shapes[i].x1 + (shapes[i].width/2.0f),
				shapes[i].y1 + (shapes[i].height / 2.0f),
				shapes[i].radius);

			ofNoFill();
			ofSetLineWidth(shapes[i].stroke_width);
			ofSetColor(
				shapes[i].stroke_r,
				shapes[i].stroke_g,
				shapes[i].stroke_b,
				shapes[i].stroke_a);
			point(
				shapes[i].x1 + (shapes[i].width / 2.0f),
				shapes[i].y1 + (shapes[i].height / 2.0f),
				shapes[i].radius);
			break;

		case Primitive2D::line:
			ofNoFill();
			ofSetLineWidth(shapes[i].stroke_width);			
			ofSetColor(
				shapes[i].stroke_r,
				shapes[i].stroke_g,
				shapes[i].stroke_b,
				shapes[i].stroke_a);
			line(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].x2,
				shapes[i].y2);

			break;

		case Primitive2D::rectangle:
			ofFill();
			ofSetLineWidth(0);
			ofSetColor(
				shapes[i].fill_r,
				shapes[i].fill_g,
				shapes[i].fill_b,
				shapes[i].fill_a);
			rectangle(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].x2,
				shapes[i].y2);
			ofNoFill();
			ofSetLineWidth(shapes[i].stroke_width);
			ofSetColor(
				shapes[i].stroke_r,
				shapes[i].stroke_g,
				shapes[i].stroke_b,
				shapes[i].stroke_a);
			rectangle(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].x2,
				shapes[i].y2);
			break;

		case Primitive2D::ellipse:       
			ofFill();
			ofSetLineWidth(0);
			ofSetCircleResolution(100);
			ofSetColor(
				shapes[i].fill_r,
				shapes[i].fill_g,
				shapes[i].fill_b,
				shapes[i].fill_a);
			ellipse(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].width,
				shapes[i].height);
			ofNoFill();
			ofSetLineWidth(shapes[i].stroke_width);
			ofSetColor(
				shapes[i].stroke_r,
				shapes[i].stroke_g,
				shapes[i].stroke_b,
				shapes[i].stroke_a);
			ellipse(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].width,
				shapes[i].height);
			break;

		case Primitive2D::triangle:
			ofFill();
			ofSetLineWidth(0);
			ofSetColor(
				shapes[i].fill_r,
				shapes[i].fill_g,
				shapes[i].fill_b,
				shapes[i].fill_a);
			triangle(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].width,
				shapes[i].height);
			ofNoFill();
			ofSetLineWidth(shapes[i].stroke_width);
			ofSetColor(
				shapes[i].stroke_r,
				shapes[i].stroke_g,
				shapes[i].stroke_b,
				shapes[i].stroke_a);
			triangle(
				shapes[i].x1,
				shapes[i].y1,
				shapes[i].width,
				shapes[i].height);

			break;
		default:
			break;
		}
	}

	draw_cursor();
	if (mouse_press) draw_outline();
}

void Dessin2D::draw_outline() const {
	float x1 = mouse_press_x;
	float y1 = mouse_press_y;
	float x2 = mouse_current_x;
	float y2 = mouse_current_y;
	float h = y2 - y1;
	float w = x2 - x1;

	ofSetLineWidth(4.0f);
	ofSetColor(255);

	ofNoFill();
	ofDrawRectRounded(x1, y1, w, h, 4.0f);

	switch (shape_mode)
	{
	case Primitive2D::point:
		ofFill();
		ofSetLineWidth(0);
		ofSetCircleResolution(100);
		ofSetColor(fill_color);
		point(
			x1 + (w/2.0f),
			y1 + (h / 2.0f),
			sqrt(pow(h, 2) + pow(w, 2)) / 2.0f);

		ofNoFill();
		ofSetLineWidth(stroke_width);
		ofSetColor(stroke_color);
		point(
			x1 + (w / 2.0f),
			y1 + (h / 2.0f),
			sqrt(pow(h, 2) + pow(w, 2)) / 2.0f);
		break;

	case Primitive2D::line:
		ofNoFill();
		ofSetLineWidth(stroke_width);
		ofSetColor(stroke_color);
		line(
			x1,
			y1,
			x2,
			y2);

		break;

	case Primitive2D::rectangle:
		ofFill();
		ofSetLineWidth(0);
		ofSetColor(fill_color);
		rectangle(
			x1,
			y1,
			x2,
			y2);
		ofNoFill();
		ofSetLineWidth(stroke_width);
		ofSetColor(stroke_color);
		rectangle(
			x1,
			y1,
			x2,
			y2);
		break;

	case Primitive2D::ellipse:
		ofFill();
		ofSetLineWidth(0);
		ofSetCircleResolution(100);
		ofSetColor(fill_color);
		ellipse(
			x1,
			y1,
			w,
			h);
		ofNoFill();
		ofSetLineWidth(stroke_width);
		ofSetColor(stroke_color);
		ellipse(
			x1,
			y1,
			w,
			h);
		break;

	case Primitive2D::triangle:
		ofFill();
		ofSetLineWidth(0);
		ofSetColor(fill_color);
		triangle(
			x1,
			y1,
			w,
			h);
		ofNoFill();
		ofSetLineWidth(stroke_width);
		ofSetColor(stroke_color);
		triangle(
			x1,
			y1,
			w,
			h);

		break;
	default:
		break;
	}
}

void Dessin2D::draw_cursor() const {
	ofSetLineWidth(2);
	ofSetColor(31);

	float x = mouse_current_x;
	float y = mouse_current_y;

	if (shape_mode == Primitive2D::line) {
		draw_cursor_line(x, y);

	}
	else if (shape_mode == Primitive2D::point) {
		draw_cursor_point(x, y);
	}
	else if (shape_mode == Primitive2D::ellipse) {
		draw_cursor_ellipse(x, y);
	}
	else if (shape_mode == Primitive2D::rectangle) {
		draw_cursor_rectangle(x, y);
	}
	else if (shape_mode == Primitive2D::triangle) {
		draw_cursor_x(x, y);
	}
}

void Dessin2D::draw_cursor_line(int x, int y) const {
	float length = 10.0f;
	float offset = 5.0f;

	if (mouse_press) {
		ofSetLineWidth(2.5f * 2.0f);
		length *= 1.5f;
		ofSetColor(cursor_press_color);
		ofFill();
	}

	ofSetLineWidth(2.0f);
	ofDrawLine(x + offset, y, x + offset + length, y);
	ofDrawLine(x - offset, y, x - offset - length, y);
	ofDrawLine(x, y + offset, x, y + offset + length);
	ofDrawLine(x, y - offset, x, y - offset - length);
	ofFill();
	ofDrawCircle(x, y, 1);
}
void Dessin2D::draw_cursor_point(int x, int y) const {
	float length = 10.0f;
	float offset = 5.0f;

	if (mouse_press) {
		length *= 2.0f;
		ofSetColor(cursor_press_color);
		ofFill();
	}
	else ofNoFill();

	ofDrawCircle(x, y, length);
}
void Dessin2D::draw_cursor_ellipse(int x, int y) const {
	int w = 40;
	int h = 20;
	if (mouse_press) {
		w *= 1.5f;
		h *= 1.5f;
		ofSetColor(cursor_press_color);
		ofFill();
	}
	else ofNoFill();

	ofDrawEllipse(x, y, w, h);
}
void Dessin2D::draw_cursor_rectangle(int x, int y) const {
	float w = 40.0f;
	float h = 20.0f;

	if (mouse_press) {
		w *= 1.5f;
		h *= 1.5f;
		ofSetColor(cursor_press_color);
		ofFill();
	}
	else ofNoFill();

	float x_centered = x - w / 2.0f;
	float y_centered = y - h / 2.0f;
	ofDrawRectangle(x_centered, y_centered, w, h);
}
void Dessin2D::draw_cursor_x(int x, int y) const {
	float length = 15.0f;
	float offset = 5.0f;
	if (mouse_press) {
		ofSetLineWidth(2.0f * 2.5f);
		length *= 1.5f;
		ofSetColor(cursor_press_color);
		ofFill();
	}


	ofSetLineWidth(2.0f);
	ofDrawLine(x - length, y - length, x - offset, y - offset);
	ofDrawLine(x + length, y - length, x + offset, y - offset);
	ofDrawLine(x - length, y + length, x - offset, y + offset);
	ofDrawLine(x + length, y + length, x + offset, y + offset);
	ofFill();
	ofDrawCircle(x, y, 1);
}

void Dessin2D::point(float x, float y, float radius) const {
	ofDrawEllipse(x, y, radius, radius);
}
void Dessin2D::line(float x1, float y1, float x2, float y2) const {
	ofDrawLine(x1, y1, x2, y2);
}

void Dessin2D::rectangle(float x1, float y1, float x2, float y2) const {

	ofDrawRectangle(x1, y1, x2 - x1, y2 - y1);
}
void Dessin2D::ellipse(float x1, float y1, float w, float h) const {


	ofDrawEllipse(x1 + w / 2.0f, y1 + h / 2.0f, w, h);
}
void Dessin2D::triangle(float x1, float y1, float w, float h) const {
	float centered_x = x1+ (w / 2.0f);

	float x2 = x1;
	float y2 = y1 + h;
	float x3 = x1 + w;
	float y3 = y1 + h;

	ofDrawTriangle(centered_x, y1, x2, y2, x3, y3);
}