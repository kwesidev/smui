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
     from   = new QLineEdit;
     toemail = new QLineEdit;
     subject = new QLineEdit;
     message = new QTextEdit;
     QLabel *logo = new QLabel;
     logo->setPixmap(*new QPixmap(":/res/logo.png"));
     send = new QPushButton(QObject::tr("&Send"));
     QFormLayout *layout = new QFormLayout;

     layout->addRow(logo);
     layout->addRow("From:",from);
     layout->addRow("To:",toemail);
     layout->addRow("Subject:",subject);
     layout->addRow("Message:",message);
     layout->addRow("",send);
     connect(send,SIGNAL(clicked()),this,SLOT(sendMail()));
     setLayout(layout);

 }


 void Mail::sendMail()
 {
     manager = new QNetworkAccessManager(this);
     connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));

     QNetworkRequest request;
     request.setUrl(QUrl("https://api.mailgun.net/v3/samples.mailgun.org/messages"));
     request.setRawHeader("User-Agent","Kwesidev/Mailgun 1.0");
     request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
     QByteArray code(this->api_key.toLocal8Bit());
     //request.setRawHeader("Authorization: Basic",*(new QByteArray(this->api_key)).toBase64());
     request.setRawHeader("Authorization: Basic",code.toBase64());


     QByteArray details;

     details.append("from='"+from->text().toLocal8Bit()+"'&");
     details.append("to='"+toemail->text().toLocal8Bit()+"'&");
     details.append("subject='"+subject->text().toLocal8Bit()+"'&");
     details.append("text='"+message->toHtml()+"'");


     //manager->get(request);
     manager->post(request,details);



 }

 void Mail::replyFinished(QNetworkReply* reply)
 {
     QByteArray outData = reply->readAll();
     QJsonObject jsonData = QJsonDocument::fromJson(outData).object();
     QMessageBox displayMess;
     QString message = jsonData.value("message").toString();
     qDebug()<<qPrintable(message);
     if(message.indexOf("Thank You.") >=0 )
     {

         displayMess.setText("Message Sent!");

     }

    else
    {

        displayMess.setText("Failed to Send");
    }


       displayMess.exec();
       reply->deleteLater();
 }

 void Mail::setApiKey(QString api_key_)
 {
      api_key = api_key_;

 }

 void Mail::setDomainKey(QString domain_key_)
 {

     domain_key = domain_key_;

 }



