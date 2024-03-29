//#####################################################################
// Copyright 2012, Ranjitha Kumar. All rights reserved.
// This software is governed by the BSD 2-Clause License.
//#####################################################################
#include "Page.h"
#include "Bento.h"
#include "BentoBlock.h"
using namespace bricolage;
//#####################################################################
// Function Page
//#####################################################################
Page::Page(QWebPage& webPage, int pageID, QString url)
:mPageID(pageID),mURL(url),mBentoTree(new BentoTree())
{
    setDOMNodes(webPage.mainFrame()->documentElement());
    Bento bento;
    bento.init(webPage.mainFrame()->documentElement());
    bento.computeBentoTree(*mBentoTree);
}
//#####################################################################
// Function setDOMNodes
//#####################################################################
void Page::setDOMNodes(const QWebElement& domNode) {
    QWebElement domChild = domNode.firstChild();
    while (!domChild.isNull()) {
        setDOMNodes(domChild);
        domChild = domChild.nextSibling();
    }
    
    mDOMNodes.append(domNode);
}
