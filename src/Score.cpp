#include "Score.h"
#include "Poco/RegularExpression.h"
#include <regex>

Score::Score(){

}

void Score::setup(map<string,string> text_with_seconds, ofColor _colorTextTyped, ofColor _colorTextToType){
    colorTextTyped = _colorTextTyped;
    colorTextToType = _colorTextToType;
    totPoints = 0;
    actualPoints = 0;
    for (map<string,string>::iterator it=text_with_seconds.begin(); it!=text_with_seconds.end(); it++) {
        string str = it->second;
        totPoints += Parser::stringWithValidChars(str, "[a-z_0-9]").length();
    }
    
    paddingRightTop = ofVec2f(30,30);
    scorePositon = ofVec2f(ofGetWidth(), 0);
    font.loadFont("BEBAS.ttf", 30);
};

void Score::onePointMore(){
    actualPoints ++;
};

void Score::draw(){
    ofPushMatrix();
        ofTranslate(scorePositon.x, scorePositon.y);
        string maxPoints = ofToString(totPoints);
        string pointsNow = ofToString(actualPoints).append(" : ");

        //draw point to reach
        ofSetColor(colorTextToType.r, colorTextToType.g,colorTextToType.b);
        ofRectangle maxPointsBounds = font.getStringBoundingBox(maxPoints, 0, 0);
        font.drawString(
                        maxPoints,
                        -maxPointsBounds.width-paddingRightTop.x,
                        (scorePositon.y + paddingRightTop.y+ maxPointsBounds.height)
        );
    
        //draw points reached
        ofSetColor(colorTextTyped.r, colorTextTyped.g,colorTextTyped.b);
        ofRectangle pointsNowBounds = font.getStringBoundingBox(pointsNow, 0, 0);
        font.drawString(
                        pointsNow,
                        -pointsNowBounds.width-maxPointsBounds.width-paddingRightTop.x,
                        (scorePositon.y + paddingRightTop.y+ pointsNowBounds.height)
                        );
    ofPopMatrix();
};

