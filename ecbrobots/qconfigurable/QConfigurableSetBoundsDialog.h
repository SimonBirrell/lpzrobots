/***************************************************************************
 *   Copyright (C) 2005 by Robot Group Leipzig                             *
 *    martius@informatik.uni-leipzig.de                                    *
 *    fhesse@informatik.uni-leipzig.de                                     *
 *    der@informatik.uni-leipzig.de                                        *
 *    guettler@informatik.uni-leipzig.de                                   *
 *    jhoffmann@informatik.uni-leipzig.de                                  *
 *    wolfgang.rabe@01019freenet.de                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *                                                                         *
 *  DESCRIPTION                                                            *
 *                                                                         *
 *   $Log$
 *   Revision 1.1  2010-12-06 17:49:34  wrabe
 *   - new QConfigurableSetBoundsDialog to change the
 *     boundaries of the Configurables (reacheble now by
 *     context menu of the ConfigurableTile (only paramval/
 *     paramint))
 *
 *                                                                         *
 ***************************************************************************/

#ifndef __QCONFIGURABLESETBOUNDSDIALOG_H_
#define __QCONFIGURABLESETBOUNDSDIALOG_H_
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QDoubleValidator>
#include <QPushButton>
#include "selforg/configurable.h"

namespace lpzrobots {
  
  class QConfigurableSetBoundsDialog : public QDialog {

    Q_OBJECT

    public:
      QConfigurableSetBoundsDialog(Configurable* config, Configurable::paramkey& key);
      virtual ~QConfigurableSetBoundsDialog();

    private slots:
      void sl_dialogAccept();
      void sl_dialogReject();
      void sl_dialogSetDefaults();


    private:
      void createDialogContentForValBounds();
      void createDialogContentForIntBounds();
      void createDialogContentError();



      QIntValidator* intValidator;
      QDoubleValidator* doubleValidator;
      QLabel* lMinBound;
      QLabel* lMaxBound;
      QLineEdit* leMinBound;
      QLineEdit* leMaxBound;
      QDialogButtonBox* buttonBox;
      QGridLayout* dialogGridLayout;
      QPushButton* pbSetDefault;

      Configurable* config;
      Configurable::paramkey key;

      enum internal_content_t {
        content_double,
        content_int,
        content_none
      } internal_content;

  };

}

#endif /* __QCONFIGURABLESETBOUNDSDIALOG_H_ */