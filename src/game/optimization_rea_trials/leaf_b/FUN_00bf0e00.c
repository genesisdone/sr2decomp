/* REA ev_b99097097e87bddd4230e736b0a6de2d79157782f64b730f7a54deb175257dc6; complete native body. */
unsigned char FUN_00bf0e00(float first, float second, float tolerance)
{
    first = first - second;
    if (first < tolerance && -first < tolerance) return 1;
    return 0;
}
