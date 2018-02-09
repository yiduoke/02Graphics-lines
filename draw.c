#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
    if (x0 > x1){
        int x_holder = x1;
        int y_holder = y1;
        x1 = x0;
        y1 = y0;
        x0 = x_holder;
        y0 = y_holder;
    }

    int A = y1 - y0;
    int B = x0 - x1;

    int x = x0;
    int y = y0;
    int d;
    float slope = 1.0 * (y1 - y0)/(x1 - x0);
    if (slope <= 1 && slope >= 0){ //octant 1
        d = 2*A + B;
        while (x <= x1){
            plot(s, c, x, y);
            if (d > 0){
                y++;
                d += 2*B;
            }
            x++;
            d += 2*A;
        }
    }
    else if (slope > 1 && slope <= INFINITY){ // octant 2
        d = A + 2*B;
        while (y <= y1){
            plot(s, c, x, y);
            if (d < 0){
                x++;
                d += 2*A;
            }
            y++;
            d += 2*B;
        }
    }
    else if (slope < 0 && slope > -1){ // octant 8
        d = 2*A-B;
        while (x <= x1){
            plot(s, c, x, y);
            if (d < 0){
                y--;
                d -= 2*B;
            }
            x++;
            d += 2*A;
        }
    }
    else if (slope <= -1 && slope >= -INFINITY){ // octant 7
        d = A - 2*B;
        printf("slope: %f\n", slope);
        while (y >= y1){
            plot(s, c, x, y);
            if (d > 0){
                x++;
                d += 2*A;
            }
            y--;
            d -= 2*B;
        }
    }
}
