#include <iostream>
#include <proj.h>
#include <iomanip>

int main()
{
    std::cout << "Our Proj Tests" << std::endl;
    PJ* P;
    PJ_COORD c, c_out;

    P = proj_create_crs_to_crs(
        PJ_DEFAULT_CTX,
        "+proj=longlat +a=6378137.0 +rf=298.2572221 +towgs84=0,0,0,0,0,0,0 +no_defs",
        "+proj=laea +lat_0=52 +lon_0=10 +x_0=4321000 +y_0=3210000 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs",
        NULL);
    if (P == 0)
        return 1;

    double lat = 50.0;
    double lon = 5.0;

    c.lpzt.phi = lat;
    c.lpzt.lam = lon;
    c.lpzt.z = 0.0;
    c.lpzt.t = HUGE_VAL;

    c_out = proj_trans(P, PJ_FWD, c);

    std::cout << std::setprecision(18) << std::fixed << "N = " << c_out.xy.y << "; E = " << c_out.xy.x << "\n";
    proj_destroy(P);
    return 0;
}