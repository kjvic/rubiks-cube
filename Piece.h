#ifndef PIECE_H
#define PIECE_H

#include <cassert>
#include <vector>
#include <string>

enum_class Color { Red, Orange, Yellow, Green, Blue, White };

public class Piece {

public:

// Parameters:
// - cube_size: If it's a 3x3 cube, then pass in cube_size of 3
// - x_coord, y_coord, z_coord: The Cartesian coordinates of the
//   *middle* of the piece
//
// Assumptions:
// - The center of the bottom corner of the cube is at the origin
//   (this allows us to use convenient zero-indexing notation)
//
Piece(int cube_size_, int x_coord_, int y_coord_, int z_coord_)
    : cube_size(cube_size_),
        x_coord(x_coord_),
        y_coord(y_coord_),
        z_coord(z_coord_) {
            
            // Ensure that each coordinate is valid for the given cube size
            std::vector<int> coords { x_coord, y_coord, z_coord };
            for (int i = 0; i < coords.size(); ++i) {
                int coord = coords[i];
                // Check if coord is valid
                if (coord >= cube_size) {
                    std::string error_message = "Invalid input: Coordinate at position "
                        + i + " (" + coord + ") is not less than cube size (" + cube_size + ").";
                    // throw InputError(error_message); TODO: define this
                    }
                }

            }

protected:
    // Parameters:
    // - turn_ccw: if true, rotate counter-clockwise (according to the RH rule)
    //
    // Note:
    // - I am making the assumption that this is a Rubik's *cube*, so
    //   all rotations are through 90 degrees
    // - In the future, this could be generalized by using an
    //   appropriate rotation matrix
    // - Furthermore, if I wanted to support megaminx-style cubes
    //   (i.e. rotations not through 90 degrees), then I could
    //   template this function to cover all "canonical rotations"
    //
    virtual void rotate_about_z(bool turn_ccw=true) {
        int sign = turn_ccw? 1 : -1;
        
        }

private:
    int cube_size;
    int x_coord;
    int y_coord;
    int z_coord;
    };

#endif
