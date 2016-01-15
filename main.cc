/*
 *SMUI
 *
 * Copyright (c) 2015 by William Kwasidev
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QDesktopWidget>
#include "mail.h"

int main(int argc,char **argv)
{
 
  QApplication app(argc,argv);
  const int WIDTH = 300;
  const int HEIGHT = 300;
  QDesktopWidget *desktop = QApplication::desktop();
  Mail box;
  box.setWindowTitle("SMUI");
  box.setFixedSize(WIDTH,HEIGHT);
  box.setApiKey("api:key-3ax6xnjp29jd6fds4gc373sgvjxteol0");
  box.setWindowIcon(*new QIcon(*new QPixmap(":/res/email.png")));
  box.move((desktop->width()-WIDTH)/2,(desktop->height()-HEIGHT)/2);
  box.show();


  return app.exec();

}
