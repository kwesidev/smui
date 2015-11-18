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


#include "mail.h"


 Mail::Mail(QWidget * parent):QWidget(parent)
 {
     QLineEdit *fname  = new QLineEdit;
     QLineEdit *email = new QLineEdit;
     QTextEdit *message  = new QTextEdit;
     QLabel *logo = new QLabel;
     logo->setPixmap(*new QPixmap(":/res/logo.png"));
     send = new QPushButton(QObject::tr("&Send"));
     QFormLayout *layout = new QFormLayout;

     layout->addRow(logo);
     layout->addRow("Email:",email);
     layout->addRow("Subject:",fname);
     layout->addRow("Message:",message);
     layout->addRow("",send);
     connect(send,SIGNAL(clicked()),this,SLOT(sendMail()));
     setLayout(layout);

 }


 void Mail::sendMail()
 {
   
  
      

 }


 void Mail::setApiKey(QString api_key_)
 {
      api_key = api_key_;

 }

 void Mail::setDomainKey(QString domain_key_)
 {

     domain_key = domain_key_;

 }


