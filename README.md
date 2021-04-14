# Mandelbrot fractal in bitmap w/ GUI zoom 

Coloring of border surrounding set can be tweeked by changing

        _red = startColor.red + colorDiff.red * hue * fabs(coords.first - coords.second);
        green = startColor.green + colorDiff.green * hue;
        blue = startColor.blue + colorDiff.blue * hue * 3*fabs(coords.first + coords.second);_
        
I have succes with setting gradient to the N'th power of iterations / MAX_ITERATIONS as this increases the contrast along the borders of the set. 
The getIteration method can be changed to compute other fractal functions such as 

      _ z_n = c * sin(z_n)_

OR
    
     _ z_n = c * z_n * (1 - z_n)_
     
The resolution of the bit map can suffer when zooming more than just a few times, but will be implemented using vector graphics in the future and
hopefully convert our raster into an .svg file
        
     
