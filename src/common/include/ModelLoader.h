/*
 * Loader.h
 *
 *  Created on: Aug 13, 2012
 *      Author: letrungkien7
 */

#ifndef LOADER_H_
#define LOADER_H_

#include <iostream>
#include <GL/glut.h>
#include <string>
#include <vector>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

typedef Vector3d Point;

class ModelLoader
{
public:
	void Load(const char *filename);
	void Draw();

	vector<Point> V;
	vector<vector<int>> F;
};

#endif /* LOADER_H_ */
