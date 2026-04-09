#include <string>
#include <fstream>
#include <sstream>
#include "svgdrawer.h"

using namespace std;

// Definition of SvgDrawer methods

SvgDrawer::SvgDrawer(std::string htmlFile, int dWidth, int dHeight)
{
  htmlFile_=htmlFile;
  drawingWidth_=dWidth;
  drawingHeight_=dHeight;
  strokeWidth_=3;
  strokeColor_="navy";
  fillColor_="none";
}

void SvgDrawer::setDrawingSize(int dWidth, int dHeight)
{
  drawingWidth_=dWidth;
  drawingHeight_=dHeight;
}

void SvgDrawer::openTag(std::string tagName,std::string attributes)
{
  htmlStream_<<'<'<<tagName<<' '<<attributes<<'>'<<endl;
}

void SvgDrawer::closeTag(std::string tagName)
{
  htmlStream_<<"</"<<tagName<<'>'<<endl;
}

void SvgDrawer::tag(std::string tagName,std::string attributes,std::string content)
{
  if (content=="") {
      emptyTag(tagName,attributes);
    }
  else {
    htmlStream_<<'<'<<tagName<<' '<<attributes<<'>';
    htmlStream_<<content;
    closeTag(tagName);
    }
}

void SvgDrawer::emptyTag(std::string tagName,std::string attributes)
{
  htmlStream_<<'<'<<tagName<<' '<<attributes<<"/>"<<endl;
}

string SvgDrawer::setAttribStyle() const
{
  ostringstream os;
  os<<"fill:"<<fillColor_;
  os<<";stroke:"<<strokeColor_;
  os<<";stroke-width:"<<strokeWidth_;
  return setAttrib("style",os.str());
}

void SvgDrawer::jscriptRefreshTag()
{
  string script="\
// Function to reload the page\n\
function reloadPage() {\n\
  // Fetch the new page content asynchronously\n\
  fetch(window.location.href)\n\
    .then(response => response.text())\n\
    .then(html => {\n\
      const parser = new DOMParser();\n\
      const doc = parser.parseFromString(html, 'text/html');\n\
      const newContent = doc.querySelector('body').innerHTML;\n\
      document.querySelector('body').innerHTML = newContent;\n\
    })\n\
    .catch(error => {\n\
      console.error('Error reloading page:', error);\n\
    });\n\
}\n\
\n\
// Reload the page every 1 second\n\
setInterval(reloadPage, 1000);\n\
";

  openTag("script");
  htmlStream_<<script;
  closeTag("script");
}

void SvgDrawer::beginDraw(string title)
{
  htmlStream_.open(htmlFile_);
  int width=drawingWidth_;
  int height=drawingHeight_;

  htmlStream_<<"<!DOCTYPE html>"<<endl;
  openTag("html");
  openTag("body");
  // HTML Title
  tag("h2","",title);
  // SVG header
  openTag("svg",setAttrib("width",width)+
          setAttrib("height",height)+
          setAttrib("xmlns","http://www.w3.org/2000/svg"));
  // Gray rectangle to show the drawing area
  tag("rect",setAttrib("width",width)+
                   setAttrib("height",height)+
                   setAttrib("x",0)+setAttrib("y",0)+
                   setAttrib("style","fill:none;stroke-width:1;stroke:gray"));
}

void SvgDrawer::endDraw()
{
  closeTag("svg");
  jscriptRefreshTag();
  closeTag("body");
  closeTag("html");
  htmlStream_.close();
}

void SvgDrawer::drawLine(double x1, double y1, double x2, double y2)
{
  tag("line",setAttrib("x1",x1)+setAttrib("y1",y1)+
             setAttrib("x2",x2)+setAttrib("y2",y2)+
             setAttribStyle());
}

void SvgDrawer::drawCircle(double centerX, double centerY, double radius)
{
  tag("circle",setAttrib("r",radius)+
             setAttrib("cx",centerX)+setAttrib("cy",centerY)+
             setAttribStyle());

}

// Definition of independant functions

std::string setAttrib(std::string name, double value)
{
  ostringstream os;
  os<<name<<"=\""<<value<<"\" ";
  return os.str();
}

std::string setAttrib(std::string name, std::string value)
{
  ostringstream os;
  os<<name<<"=\""<<value<<"\" ";
  return os.str();
}
