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
#ifndef MAIL_H
#define MAIL_H
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QFormLayout>
#include <QTextEdit>
#include <QIcon>
#include <QPixmap>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>

class Mail : public QWidget
{

    Q_OBJECT

  public:
    Mail(QWidget * parent = 0);
    void setApiKey(QString api_key_);
    void setDomainKey(QString domain_key_);


  private:
    QPushButton *send;
    QLineEdit *from;
    QLineEdit *toemail;
    QTextEdit *message;
    QLineEdit *subject;
    QString api_key;
    QString domain_key;
    QNetworkAccessManager * manager;
  private slots:
    void sendMail();
    void replyFinished(QNetworkReply *reply);

};


#endif // MAIL_H

