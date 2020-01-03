#pragma once

#include <vector>
#include "Vector.hpp"
#include "Section.hpp"
#include "Geometry.hpp"
#include "utils.hpp"

Vector movePointsToSections(const std::vector<Vector>& points,
const std::vector<Section> sections,Vector v);

Vector movePointToSection(Vector point,Section section,Vector v);
