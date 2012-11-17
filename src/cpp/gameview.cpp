/*
  Copyright 2012 Mats Sjöberg
  
  This file is part of the Heebo programme.
  
  Heebo is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Heebo is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Heebo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "gameview.h"

#include <QDeclarativeEngine>
#include <QGraphicsObject>

//------------------------------------------------------------------------------

GameView::GameView(QWidget* parent) : QDeclarativeView(parent) {
  readSettings();

  m_mapset = new GameMapSet(":/map.dat", m_level, this);
  connect(m_mapset, SIGNAL(levelChanged()), this, SLOT(onLevelChanged()));

  rootContext()->setContextProperty("mapset", m_mapset);
  rootContext()->setContextProperty("gameview", this);

  setSource(QUrl("qrc:///qml/main.qml"));
  aboutView =  new QDeclarativeView();
  aboutView->hide();
  aboutView->setSource(QUrl("qrc:///qml/AboutPage.qml"));
  aboutView->rootContext()->setContextProperty("gameview", this);

  helpView = new QDeclarativeView();
  helpView->hide();
  helpView->setSource(QUrl("qrc:///qml/HelpPage.qml"));
  helpView->rootContext()->setContextProperty("gameview", this);
}

//------------------------------------------------------------------------------

QString GameView::platform() const {
#ifdef HARMATTAN
  return "harmattan";
#else
  return "desktop";
#endif
}

//------------------------------------------------------------------------------

void GameView::onLevelChanged() {
  writeSettings();
}

//------------------------------------------------------------------------------

void GameView::writeSettings() {
  QSettings s("heebo", "heebo");
  s.beginGroup("Mapset");
  s.setValue("level", m_mapset->level());
  s.endGroup();
}

//------------------------------------------------------------------------------

void GameView::readSettings() {
  QSettings s("heebo", "heebo");
  s.beginGroup("Mapset");
  m_level = s.value("level", 0).toInt();
  s.endGroup();
}

//------------------------------------------------------------------------------

void GameView::hideAboutPage(){
	aboutView->hide();
	showFullScreen();
}
void GameView::showAboutPage(){
	hide();
	aboutView->showFullScreen();
}

void GameView:: hideHelpPage(){
	helpView->hide();
	showFullScreen();
}
void GameView::showHelpPage(){
	hide();
	helpView->showFullScreen();
}

void GameView::quitApp() {
  writeSettings();
  qApp->quit();
}
