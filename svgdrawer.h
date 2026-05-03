#ifndef SVGDRAWER_H
#define SVGDRAWER_H

#include <string>
#include <fstream>


class SvgDrawer
{
  // Private fields
  std::string htmlFile_;
  int drawingWidth_;
  int drawingHeight_;
  std::ofstream htmlStream_;
  std::string strokeColor_;
  float strokeWidth_;
  std::string fillColor_;

  // Private methods
  void openTag(std::string tagName,std::string attribute="");
  void closeTag(std::string tagName);
  void emptyTag(std::string tagName,std::string attribute="");
  void tag(std::string tagName,std::string attribute="",std::string content="");
  std::string setAttribStyle() const;
  void jscriptRefreshTag();

public:

  //! Constructor
  SvgDrawer(std::string htmlFile, int dWidth=400, int dHeight=400);

  // Modified by Johann
  // Used to set the turtle origin based on the drawing size
  int drawingWidth() const { return drawingWidth_; };
  int drawingHeight() const { return drawingHeight_; };

  //! Set the drawing area size
  void setDrawingSize(int dWidth,int dHeight);

  //! Get the stroke color
  std::string strokeColor() const
    {return strokeColor_;}

  //! Set the stroke color
  void setStrokeColor(std::string sColor)
    {strokeColor_=sColor;}

  //! Get the stroke width
  float strokeWidth() const
    {return strokeWidth_;}

  //! Set the stroke width
  void setStrokeWidth(float sWidth)
    {strokeWidth_=sWidth;}

  //! Get the fill color
  std::string fillColor() const
    {return fillColor_;}

  //! Set the fill color
  void setFillColor(std::string fColor)
    {fillColor_=fColor;}

  //! Call to start the drawing
  void beginDraw(std::string title);

  //! Call to end the drawing
  void endDraw();

  //! Draw a line
  void drawLine(double x1,double y1,double x2,double y2);

  //! Draw a circle
  void drawCircle(double centerX,double centerY,double radius);
};

std::string setAttrib(std::string name, double value);
std::string setAttrib(std::string name, std::string value);

#endif // SVGDRAWER_H
