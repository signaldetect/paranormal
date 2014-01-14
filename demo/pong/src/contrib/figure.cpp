#include "figure.h"

void Figure::actionWindowCreated()
{
  actualize<p__the(FigureEffector::figureDrawingReady)>
           (/*drawable=*/asDrawable());
}
