#pragma once
double integral(double(*f)(double x), double a, double b, int n) {
	double step = (b - a) / n;  // width of each small rectangle
	double area = 0.0;  // signed area
	for (int i = 0; i < n; i++) {
		area += f(a + (i + 0.5) * step) * step; // sum up each small rectangle
	}
	return area;
}