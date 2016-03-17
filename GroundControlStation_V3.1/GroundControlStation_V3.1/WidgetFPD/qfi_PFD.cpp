/***************************************************************************//**
 * @file qfi_PFD.cpp
 * @author  Marek M. Cel <marekcel@mscsim.org>
 *
 * @section LICENSE
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * This file is part of QFlightInstruments. You can redistribute and modify it
 * under the terms of GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Further information about the GNU General Public License can also be found
 * on the world wide web at http://www.gnu.org.
 *
 * ---
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef _QFI_PFD_CPP_
#define _QFI_PFD_CPP_
#endif

//##############################################################################

#ifdef WIN32
#   include <float.h>
#endif

#include <math.h>
#include <stdio.h>
#include <QDebug>
#include "qfi_PFD.h"

//##############################################################################

qfi_PFD::qfi_PFD( QWidget * pParent ) :
    QGraphicsView ( pParent ),

    m_pScene ( 0 ),

    m_pADI ( 0 ),
    m_pALT ( 0 ),
    m_pASI ( 0 ),
    m_pHSI ( 0 ),
    m_pVSI ( 0 ),

    m_pItemBack ( 0 ),
    m_pItemMask ( 0 ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_iOriginalHeight ( 300 ),
    m_iOriginalWidth  ( 300 ),

    m_iBackZ (   0 ),
    m_iMaskZ ( 100 )
{
    reset();

    m_pScene = new QGraphicsScene( this );
    setScene( m_pScene );

    m_pScene->clear();

    m_pADI = new qfi_PFD::ADI( m_pScene );
    m_pALT = new qfi_PFD::ALT( m_pScene );
    m_pASI = new qfi_PFD::ASI( m_pScene );
    m_pHSI = new qfi_PFD::HSI( m_pScene );
    m_pVSI = new qfi_PFD::VSI( m_pScene );

    init();
}

//##############################################################################

qfi_PFD::~qfi_PFD()
{
    if ( m_pScene )
    {
        m_pScene->clear();
        delete m_pScene;
        m_pScene = 0;
    }

    reset();

    if ( m_pADI ) delete m_pADI; m_pADI = 0;
    if ( m_pALT ) delete m_pALT; m_pALT = 0;
    if ( m_pASI ) delete m_pASI; m_pASI = 0;
    if ( m_pHSI ) delete m_pHSI; m_pHSI = 0;
    if ( m_pVSI ) delete m_pVSI; m_pVSI = 0;
}

//##############################################################################

void qfi_PFD::reinit()
{
    if ( m_pScene )
    {
        m_pScene->clear();

        init();
    }
}

//##############################################################################

void qfi_PFD::update()
{
    updateView();
}

//##############################################################################

void qfi_PFD::resizeEvent( QResizeEvent * pEvent )
{
    /////////////////////////////////////
    QGraphicsView::resizeEvent( pEvent );
    /////////////////////////////////////

    reinit();
}

//##############################################################################

void qfi_PFD::init()
{
    m_fScaleX = (float)width()  / (float)m_iOriginalWidth;
    m_fScaleY = (float)height() / (float)m_iOriginalHeight;

    m_pADI->init( m_fScaleX, m_fScaleY );
    m_pALT->init( m_fScaleX, m_fScaleY );
    m_pASI->init( m_fScaleX, m_fScaleY );
    m_pHSI->init( m_fScaleX, m_fScaleY );
    m_pVSI->init( m_fScaleX, m_fScaleY );

    m_pItemBack = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_back.svg" );
    m_pItemBack->setCacheMode( QGraphicsItem::NoCache );
    m_pItemBack->setZValue( m_iBackZ );
    m_pItemBack->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pScene->addItem( m_pItemBack );

    m_pItemMask = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_mask.svg" );
    m_pItemMask->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMask->setZValue( m_iMaskZ );
    m_pItemMask->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pScene->addItem( m_pItemMask );

    m_pItemLight = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_redlight.svg" );
    m_pItemLight->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLight->setZValue( m_iMaskZ );
    m_pItemLight->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLight->moveBy(-90,-66);
    m_pScene->addItem( m_pItemLight );
//    m_pItemLight->hide();

    m_pItemLight2 = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_redlight2.svg" );
    m_pItemLight2->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLight2->setZValue( m_iMaskZ );
    m_pItemLight2->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLight2->moveBy(25,-66);
    m_pScene->addItem( m_pItemLight2 );
//    m_pItemLight2->hide();




    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}


//##############################################################################

void qfi_PFD::reset()
{
    m_pItemBack = 0;
    m_pItemMask = 0;
}

//##############################################################################

void qfi_PFD::updateView()
{
    m_fScaleX = (float)width()  / (float)m_iOriginalWidth;
    m_fScaleY = (float)height() / (float)m_iOriginalHeight;

    m_pADI->update( m_fScaleX, m_fScaleY );
    m_pALT->update( m_fScaleX, m_fScaleY );
    m_pASI->update( m_fScaleX, m_fScaleY );
    m_pHSI->update( m_fScaleX, m_fScaleY );
    m_pVSI->update( m_fScaleX, m_fScaleY );

    m_pScene->update();
}

//##############################################################################
//##############################################################################
//##############################################################################

qfi_PFD::ADI::ADI( QGraphicsScene * pScene ) :
    m_pScene ( pScene ),

    m_pItemLadd  ( 0 ),
    m_pItemRoll  ( 0 ),
    m_pItemSlip  ( 0 ),
    m_pItemIlsGs ( 0 ),
    m_pItemIlsLc ( 0 ),
    m_pItemMask  ( 0 ),

    m_fRoll     ( 0.0f ),
    m_fPitch    ( 0.0f ),
    m_fSideSlip ( 0.0f ),
    m_fIlsGs    ( 0.0f ),
    m_fIlsLc    ( 0.0f ),

    m_iIlsGs ( 0 ),
    m_iIlsLc ( 0 ),

    m_fLaddDeltaX_new  ( 0.0f ),
    m_fLaddDeltaX_old  ( 0.0f ),
    m_fLaddDeltaY_new  ( 0.0f ),
    m_fLaddDeltaY_old  ( 0.0f ),
    m_fSlipDeltaX_new  ( 0.0f ),
    m_fSlipDeltaX_old  ( 0.0f ),
    m_fIlsLcDeltaX_new ( 0.0f ),
    m_fIlsLcDeltaX_old ( 0.0f ),
    m_fIlsGsDeltaY_new ( 0.0f ),
    m_fIlsGsDeltaY_old ( 0.0f ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_fOriginalPixPerDeg (  3.0f ),
    m_fMaxSlipDeflection ( 10.0f ),
    m_fMaxIlsDeflection  ( 25.0f ),

    m_OriginalAdiCtr   ( 150.0f ,  125.0f ),
    m_OriginalLaddPos  (  70.0f , -234.0f ),
    m_OriginalRollPos  (  60.0f ,   35.0f ),
    m_OriginalSlipPos  ( 143.5f ,   58.0f ),
    m_OriginalIlsGsPos ( 125.0f ,  125.0f ),
    m_OriginalIlsLcPos ( 149.0f ,  101.0f ),

    m_iLaddZ ( 10 ),
    m_iRollZ ( 20 ),
    m_iSlipZ ( 30 ),
    m_iIls_Z ( 40 ),
    m_iMaskZ ( 50 )
{
    reset();
}

//##############################################################################

void qfi_PFD::ADI::init( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    reset();

    m_pItemLadd = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_ladd.svg" );
    m_pItemLadd->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLadd->setZValue( m_iLaddZ );
    m_pItemLadd->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLadd->setTransformOriginPoint( m_OriginalAdiCtr - m_OriginalLaddPos );
    m_pItemLadd->moveBy( m_fScaleX * m_OriginalLaddPos.x(), m_fScaleY * m_OriginalLaddPos.y() );
    m_pScene->addItem( m_pItemLadd );

    m_pItemRoll = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_roll.svg" );
    m_pItemRoll->setCacheMode( QGraphicsItem::NoCache );
    m_pItemRoll->setZValue( m_iRollZ );
    m_pItemRoll->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemRoll->setTransformOriginPoint( m_OriginalAdiCtr - m_OriginalRollPos );
    m_pItemRoll->moveBy( m_fScaleX * m_OriginalRollPos.x(), m_fScaleY * m_OriginalRollPos.y() );
    m_pScene->addItem( m_pItemRoll );

    m_pItemSlip = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_slip.svg" );
    m_pItemSlip->setCacheMode( QGraphicsItem::NoCache );
    m_pItemSlip->setZValue( m_iSlipZ );
    m_pItemSlip->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemSlip->moveBy( m_fScaleX * m_OriginalSlipPos.x(), m_fScaleY * m_OriginalSlipPos.y() );
    m_pScene->addItem( m_pItemSlip );

    m_pItemIlsGs = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_ils_gs.svg" );
    m_pItemIlsGs->setCacheMode( QGraphicsItem::NoCache );
    m_pItemIlsGs->setZValue( m_iIls_Z );
    m_pItemIlsGs->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemIlsGs->moveBy( m_fScaleX * m_OriginalIlsGsPos.x(), m_fScaleY * m_OriginalIlsGsPos.y() );
    m_pScene->addItem( m_pItemIlsGs );

    m_pItemIlsLc = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_ils_lc.svg" );
    m_pItemIlsLc->setCacheMode( QGraphicsItem::NoCache );
    m_pItemIlsLc->setZValue( m_iIls_Z );
    m_pItemIlsLc->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemIlsLc->moveBy( m_fScaleX * m_OriginalIlsLcPos.x(), m_fScaleY * m_OriginalIlsLcPos.y() );
    m_pScene->addItem( m_pItemIlsLc );

    m_pItemMask = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_adi_mask.svg" );
    m_pItemMask->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMask->setZValue( m_iMaskZ );
    m_pItemMask->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pScene->addItem( m_pItemMask );


    m_pItemDispitch = new QGraphicsTextItem( QString( "00.0" ) );
    m_pItemDispitch->setCacheMode( QGraphicsItem::NoCache );
    m_pItemDispitch->setZValue( 120 );
    m_pItemDispitch->setTextInteractionFlags( Qt::NoTextInteraction );
    m_pItemDispitch->setDefaultTextColor(QColor(255,255,255));
    m_pItemDispitch->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemDispitch->moveBy(75,200);
    m_pScene->addItem( m_pItemDispitch );

    m_pItemDisRoll = new QGraphicsTextItem( QString( "00.0" ) );
    m_pItemDisRoll->setCacheMode( QGraphicsItem::NoCache );
    m_pItemDisRoll->setZValue( 120 );
    m_pItemDisRoll->setTextInteractionFlags( Qt::NoTextInteraction );
    m_pItemDisRoll->setDefaultTextColor(QColor(255,255,255));
    m_pItemDisRoll->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemDisRoll->moveBy(203,200);
    m_pScene->addItem( m_pItemDisRoll );

    update( fScaleX, fScaleY );
}

//##############################################################################

void qfi_PFD::ADI::update( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    updateLadd();
    updateRoll();
    updateSideSlip();
    updateIls();

    m_fLaddDeltaX_old  = m_fLaddDeltaX_new;
    m_fLaddDeltaY_old  = m_fLaddDeltaY_new;
    m_fSlipDeltaX_old  = m_fSlipDeltaX_new;
    m_fIlsLcDeltaX_old = m_fIlsLcDeltaX_new;
    m_fIlsGsDeltaY_old = m_fIlsGsDeltaY_new;
}

//##############################################################################

void qfi_PFD::ADI::setRoll( float fRoll )
{
    m_fRoll = fRoll;

    if ( m_fRoll < -180.0f ) m_fRoll = -180.0f;
    if ( m_fRoll >  180.0f ) m_fRoll =  180.0f;
}

//##############################################################################

void qfi_PFD::ADI::setPitch( float fPitch )
{
    m_fPitch = fPitch;

    if ( m_fPitch < -90.0f ) m_fPitch = -90.0f;
    if ( m_fPitch >  90.0f ) m_fPitch =  90.0f;
}

//##############################################################################

void qfi_PFD::ADI::setSideSlip( float fSideSlip )
{
    m_fSideSlip = fSideSlip;

    if ( m_fSideSlip < -1.0f ) m_fSideSlip = -1.0f;
    if ( m_fSideSlip >  1.0f ) m_fSideSlip =  1.0f;
}

//##############################################################################

void qfi_PFD::ADI::setIlsGs( float fIlsGs, int iIlsGs )
{
    m_fIlsGs = fIlsGs;

    if ( m_fIlsGs < -1.0f ) m_fIlsGs = -1.0f;
    if ( m_fIlsGs >  1.0f ) m_fIlsGs =  1.0f;

    m_iIlsGs = ( iIlsGs ) ? 1 : 0;
}

//##############################################################################

void qfi_PFD::ADI::setIlsLc( float fIlsLc, int iIlsLc )
{
    m_fIlsLc = fIlsLc;

    if ( m_fIlsLc < -1.0f ) m_fIlsLc = -1.0f;
    if ( m_fIlsLc >  1.0f ) m_fIlsLc =  1.0f;

    m_iIlsLc = ( iIlsLc ) ? 1 : 0;
}

//##############################################################################

void qfi_PFD::ADI::reset()
{
    m_pItemLadd = 0;
    m_pItemRoll = 0;
    m_pItemSlip = 0;

    m_pItemIlsGs = 0;
    m_pItemIlsLc = 0;

    m_pItemMask = 0;

    m_fRoll     = 0.0f;
    m_fPitch    = 0.0f;
    m_fSideSlip = 0.0f;
    m_fIlsGs    = 0.0f;
    m_fIlsLc    = 0.0f;

    m_fLaddDeltaX_new  = 0.0f;
    m_fLaddDeltaX_old  = 0.0f;
    m_fLaddDeltaY_new  = 0.0f;
    m_fLaddDeltaY_old  = 0.0f;
    m_fSlipDeltaX_new  = 0.0f;
    m_fSlipDeltaX_old  = 0.0f;
    m_fIlsLcDeltaX_new = 0.0f;
    m_fIlsLcDeltaX_old = 0.0f;
    m_fIlsGsDeltaY_new = 0.0f;
    m_fIlsGsDeltaY_old = 0.0f;
}

//##############################################################################

void qfi_PFD::ADI::updateLadd()
{
    m_pItemLadd->setRotation( - m_fRoll );

    float fRoll_rad = M_PI * m_fRoll / 180.0;

    float fDelta  = m_fOriginalPixPerDeg * m_fPitch;

    m_fLaddDeltaX_new = m_fScaleX * fDelta * sin( fRoll_rad );
    m_fLaddDeltaY_new = m_fScaleY * fDelta * cos( fRoll_rad );

    m_pItemLadd->moveBy( m_fLaddDeltaX_new - m_fLaddDeltaX_old, m_fLaddDeltaY_new - m_fLaddDeltaY_old );
    m_pItemDispitch->setPlainText( QString("%1").arg(m_fPitch, 3, 'f', 1, QChar('0')));
    m_pItemDisRoll->setPlainText( QString("%1").arg(m_fRoll, 3, 'f', 1, QChar('0')));
}

//##############################################################################

void qfi_PFD::ADI::updateRoll()
{
    m_pItemRoll->setRotation( - m_fRoll );
}

//##############################################################################

void qfi_PFD::ADI::updateSideSlip()
{
    m_fSlipDeltaX_new = m_fScaleX * m_fMaxSlipDeflection * m_fSideSlip;

    m_pItemSlip->moveBy( m_fSlipDeltaX_new - m_fSlipDeltaX_old, 0 );
}

//##############################################################################

void qfi_PFD::ADI::updateIls()
{
    if ( m_iIlsLc )
    {
        m_pItemIlsLc->setVisible( true );

        m_fIlsLcDeltaX_new = m_fScaleX * m_fMaxIlsDeflection * m_fIlsLc;

        m_pItemIlsLc->moveBy( m_fIlsLcDeltaX_new - m_fIlsLcDeltaX_old, 0.0f );
    }
    else
    {
        m_pItemIlsLc->setVisible( false );
        m_fIlsLcDeltaX_new = m_fIlsLcDeltaX_old;
    }

    if ( m_iIlsGs )
    {

        m_pItemIlsGs->setVisible( true );

        m_fIlsGsDeltaY_new = m_fScaleY * m_fMaxIlsDeflection * m_fIlsGs;

        m_pItemIlsGs->moveBy( 0.0f, m_fIlsGsDeltaY_old - m_fIlsGsDeltaY_new );
    }
    else
    {

        m_pItemIlsGs->setVisible( false );
        m_fIlsGsDeltaY_new = m_fIlsGsDeltaY_old;
    }
}

//##############################################################################
//##############################################################################
//##############################################################################

qfi_PFD::ALT::ALT( QGraphicsScene * pScene ) :
    m_pScene ( pScene ),

    m_pItemBack     ( 0 ),
    m_pItemScale1   ( 0 ),
    m_pItemScale2   ( 0 ),
    m_pItemLabel1   ( 0 ),
    m_pItemLabel2   ( 0 ),
    m_pItemLabel3   ( 0 ),
    m_pItemGround   ( 0 ),
    m_pItemFrame    ( 0 ),
    m_pItemAltitude ( 0 ),
    m_pItemPressure ( 0 ),

    m_FrameTextColor ( 255, 255, 255 ),
    m_PressTextColor ( 255, 255, 255 ),
    m_LabelsColor    ( 255, 255, 255 ),

    m_fAltitude ( 0.0f ),
    m_fPressure ( 0.0f ),

    m_fScale1DeltaY_new ( 0.0f ),
    m_fScale1DeltaY_old ( 0.0f ),
    m_fScale2DeltaY_new ( 0.0f ),
    m_fScale2DeltaY_old ( 0.0f ),
    m_fGroundDeltaY_new ( 0.0f ),
    m_fGroundDeltaY_old ( 0.0f ),
    m_fLabelsDeltaY_new ( 0.0f ),
    m_fLabelsDeltaY_old ( 0.0f ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_fOriginalPixPerAlt   ( 0.150f ),
    m_fOriginalScaleHeight ( 300.0f ),
    m_fOriginalLabelsX     ( 260.0f ),
    m_fOriginalLabel1Y     (  50.0f ),
    m_fOriginalLabel2Y     ( 125.0f ),
    m_fOriginalLabel3Y     ( 200.0f ),

    m_OriginalBackPos     ( 240.0f ,   50.0f ),
    m_OriginalScale1Pos   ( 240.0f , -174.5f ),
    m_OriginalScale2Pos   ( 240.0f , -474.5f ),
    m_OriginalGroundPos   ( 240.5f ,  124.5f ),
    m_OriginalFramePos    ( 239.5f ,  117.0f ),
    m_OriginalAltitudeCtr ( 260.0f ,  125.0f ),
    m_OriginalPressureCtr ( 258.0f ,  220.0f ),

    m_iBackZ      (  60 ),
    m_iScaleZ     (  70 ),
    m_iLabelsZ    (  70 ),
    m_iGroundZ    (  70 ),
    m_iFrameZ     ( 110 ),
    m_iFrameTextZ ( 120 ),
    m_iPressTextZ ( 120 )
{
#   ifdef WIN32
    m_FrameTextFont.setFamily( "courier" );
    m_FrameTextFont.setPointSizeF( 7.0f );
    m_FrameTextFont.setStretch( QFont::Condensed );
    m_FrameTextFont.setWeight( QFont::Bold );

    m_PressTextFont.setFamily( "courier" );
    m_PressTextFont.setPointSizeF( 7.0f );
    m_PressTextFont.setStretch( QFont::Condensed );
    m_PressTextFont.setWeight( QFont::Bold );
#   else
    m_FrameTextFont.setFamily( "courier" );
    m_FrameTextFont.setPointSizeF( 9.0f );
    m_FrameTextFont.setStretch( QFont::Condensed );
    m_FrameTextFont.setWeight( QFont::Bold );

    m_PressTextFont.setFamily( "courier" );
    m_PressTextFont.setPointSizeF( 9.0f );
    m_PressTextFont.setStretch( QFont::Condensed );
    m_PressTextFont.setWeight( QFont::Bold );
#   endif

    m_LabelsFont.setFamily( "courier" );
    m_LabelsFont.setPointSizeF( 7.0f );
    m_LabelsFont.setStretch( QFont::Condensed );
    m_LabelsFont.setWeight( QFont::Bold );

    reset();
}

//##############################################################################

void qfi_PFD::ALT::init( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    reset();

    m_pItemBack = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_alt_back.svg" );
    m_pItemBack->setCacheMode( QGraphicsItem::NoCache );
    m_pItemBack->setZValue( m_iBackZ );
    m_pItemBack->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemBack->moveBy( m_fScaleX * m_OriginalBackPos.x(), m_fScaleY * m_OriginalBackPos.y() );
    m_pScene->addItem( m_pItemBack );

    m_pItemScale1 = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_alt_scale.svg" );
    m_pItemScale1->setCacheMode( QGraphicsItem::NoCache );
    m_pItemScale1->setZValue( m_iScaleZ );
    m_pItemScale1->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemScale1->moveBy( m_fScaleX * m_OriginalScale1Pos.x(), m_fScaleY * m_OriginalScale1Pos.y() );
    m_pScene->addItem( m_pItemScale1 );

    m_pItemScale2 = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_alt_scale.svg" );
    m_pItemScale2->setCacheMode( QGraphicsItem::NoCache );
    m_pItemScale2->setZValue( m_iScaleZ );
    m_pItemScale2->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemScale2->moveBy( m_fScaleX * m_OriginalScale2Pos.x(), m_fScaleY * m_OriginalScale2Pos.y() );
    m_pScene->addItem( m_pItemScale2 );

    m_pItemLabel1 = new QGraphicsTextItem( QString( "99999" ) );
    m_pItemLabel1->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel1->setZValue( m_iLabelsZ );
    m_pItemLabel1->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel1->setFont( m_LabelsFont );
    m_pItemLabel1->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel1->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel1->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel1Y - m_pItemLabel1->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel1 );

    m_pItemLabel2 = new QGraphicsTextItem( QString( "99999" ) );
    m_pItemLabel2->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel2->setZValue( m_iLabelsZ );
    m_pItemLabel2->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel2->setFont( m_LabelsFont );
    m_pItemLabel2->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel2->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel2->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel2Y - m_pItemLabel2->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel2 );

    m_pItemLabel3 = new QGraphicsTextItem( QString( "99999" ) );
    m_pItemLabel3->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel3->setZValue( m_iLabelsZ );
    m_pItemLabel3->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel3->setFont( m_LabelsFont );
    m_pItemLabel3->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel3->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel3->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel3Y - m_pItemLabel3->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel3 );

    m_pItemGround = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_alt_ground.svg" );
    m_pItemGround->setCacheMode( QGraphicsItem::NoCache );
    m_pItemGround->setZValue( m_iGroundZ );
    m_pItemGround->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemGround->moveBy( m_fScaleX * m_OriginalGroundPos.x(), m_fScaleY * m_OriginalGroundPos.y() );
    m_pScene->addItem( m_pItemGround );

    m_pItemFrame = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_alt_frame.svg" );
    m_pItemFrame->setCacheMode( QGraphicsItem::NoCache );
    m_pItemFrame->setZValue( m_iFrameZ );
    m_pItemFrame->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemFrame->moveBy( m_fScaleX * m_OriginalFramePos.x(), m_fScaleY * m_OriginalFramePos.y() );
    m_pScene->addItem( m_pItemFrame );

    m_pItemAltitude = new QGraphicsTextItem( QString( "0" ) );
    m_pItemAltitude->setCacheMode( QGraphicsItem::NoCache );
    m_pItemAltitude->setZValue( m_iFrameTextZ );
    m_pItemAltitude->setDefaultTextColor( m_FrameTextColor );
    m_pItemAltitude->setFont( m_FrameTextFont );
    m_pItemAltitude->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemAltitude->moveBy( m_fScaleX * ( m_OriginalAltitudeCtr.x() - m_pItemAltitude->boundingRect().width()  / 2.0f-25 ),
                             m_fScaleY * ( m_OriginalAltitudeCtr.y() - m_pItemAltitude->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemAltitude );

    m_SpeedMark = new QGraphicsTextItem( QString( "ABS" ) );
    m_SpeedMark->setCacheMode( QGraphicsItem::NoCache );
    m_SpeedMark->setZValue( m_iFrameTextZ );
    m_SpeedMark->setDefaultTextColor(QColor(0,255,0));
    m_SpeedMark->setFont( m_FrameTextFont );
    m_SpeedMark->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_SpeedMark->moveBy( m_fScaleX * ( m_OriginalAltitudeCtr.x() - m_pItemAltitude->boundingRect().width()  / 2.0f-10 ),
                             m_fScaleY * ( m_OriginalAltitudeCtr.y() - m_pItemAltitude->boundingRect().height() / 2.0f-100 ) );
    m_pScene->addItem( m_SpeedMark );

    m_pItemPressure = new QGraphicsTextItem( QString( "0.0" ) );
    m_pItemPressure->setCacheMode( QGraphicsItem::NoCache );
    m_pItemPressure->setZValue( m_iPressTextZ );
    m_pItemPressure->setDefaultTextColor( m_PressTextColor );
    m_pItemPressure->setFont( m_PressTextFont );
    m_pItemPressure->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemPressure->moveBy( m_fScaleX * ( m_OriginalPressureCtr.x() - m_pItemPressure->boundingRect().width()  / 2.0f -18),
                             m_fScaleY * ( m_OriginalPressureCtr.y() - m_pItemPressure->boundingRect().height() / 2.0f )+4 );
    m_pScene->addItem( m_pItemPressure );

    update( fScaleX, fScaleY );
}

//##############################################################################

void qfi_PFD::ALT::update( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    updateAltitude();
    updatePressure();

    m_fScale1DeltaY_old = m_fScale1DeltaY_new;
    m_fScale2DeltaY_old = m_fScale2DeltaY_new;
    m_fGroundDeltaY_old = m_fGroundDeltaY_new;
    m_fLabelsDeltaY_old = m_fLabelsDeltaY_new;

}

//##############################################################################

void qfi_PFD::ALT::setAltitude( float fAltitude )
{
    m_fAltitude = fAltitude;

    if ( m_fAltitude <     0.0f ) m_fAltitude =     0.0f;
    if ( m_fAltitude > 99999.0f ) m_fAltitude = 99999.0f;
}

//##############################################################################

void qfi_PFD::ALT::setPressure( float fPressure )
{
    m_fPressure = fPressure;

    if ( m_fPressure <    0.0 ) m_fPressure =    0.0;
    if ( m_fPressure > 9999.0 ) m_fPressure = 9999.0;
}

//##############################################################################

void qfi_PFD::ALT::reset()
{
    m_pItemBack     = 0;
    m_pItemScale1   = 0;
    m_pItemScale2   = 0;
    m_pItemLabel1   = 0;
    m_pItemLabel2   = 0;
    m_pItemLabel3   = 0;
    m_pItemGround   = 0;
    m_pItemFrame    = 0;
    m_pItemAltitude = 0;
    m_pItemPressure = 0;

    m_fAltitude = 0.0f;
    m_fPressure = 0.0f;

    m_fScale1DeltaY_new = 0.0f;
    m_fScale1DeltaY_old = 0.0f;
    m_fScale2DeltaY_new = 0.0f;
    m_fScale2DeltaY_old = 0.0f;
    m_fGroundDeltaY_new = 0.0f;
    m_fGroundDeltaY_old = 0.0f;
    m_fLabelsDeltaY_new = 0.0f;
    m_fLabelsDeltaY_old = 0.0f;
}

//##############################################################################

void qfi_PFD::ALT::updateAltitude()
{

    m_pItemAltitude->setPlainText( QString("%1").arg(m_fAltitude, 5, 'f', 0, QChar(' ')) );

    updateScale();
    updateScaleLabels();
}

//##############################################################################

void qfi_PFD::ALT::updatePressure()
{
    if ( m_fPressure < 100.0f )
    {
        m_pItemPressure->setPlainText( QString("%1").arg(m_fPressure, 6, 'f', 2, QChar(' ')) );
    }
    else
    {
        m_pItemPressure->setPlainText( QString("%1").arg(m_fPressure, 6, 'f', 1, QChar(' ')) );
    }
}

//##############################################################################

void qfi_PFD::ALT::updateScale()
{
    m_fScale1DeltaY_new = m_fScaleY * m_fOriginalPixPerAlt * m_fAltitude;
    m_fScale2DeltaY_new = m_fScale1DeltaY_new;
    m_fGroundDeltaY_new = m_fScale1DeltaY_new;

    float fScaleSingleHeight = m_fScaleY * m_fOriginalScaleHeight;
    float fScalefloatHeight = m_fScaleY * m_fOriginalScaleHeight * 2.0f;

    while ( m_fScale1DeltaY_new > fScaleSingleHeight + m_fScaleY * 74.5f )
    {
        m_fScale1DeltaY_new = m_fScale1DeltaY_new - fScalefloatHeight;
    }

    while ( m_fScale2DeltaY_new > fScalefloatHeight + m_fScaleY * 74.5f )
    {
        m_fScale2DeltaY_new = m_fScale2DeltaY_new - fScalefloatHeight;
    }

    if ( m_fGroundDeltaY_new > m_fScaleY * 100.0f ) m_fGroundDeltaY_new = m_fScaleY * 100.0f;

    m_pItemScale1->moveBy( 0.0f, m_fScale1DeltaY_new - m_fScale1DeltaY_old );
    m_pItemScale2->moveBy( 0.0f, m_fScale2DeltaY_new - m_fScale2DeltaY_old );
    m_pItemGround->moveBy( 0.0f, m_fGroundDeltaY_new - m_fGroundDeltaY_old );
}

//##############################################################################

void qfi_PFD::ALT::updateScaleLabels()
{
    int iTmp = floor( m_fAltitude + 0.1f );
    int iAlt = iTmp - ( iTmp % 100 );

    float fAlt1 = (float)iAlt + 100.0f;
    float fAlt2 = (float)iAlt;
    float fAlt3 = (float)iAlt - 100.0f;

    m_fLabelsDeltaY_new = m_fScaleY * m_fOriginalPixPerAlt * m_fAltitude;

    while ( m_fLabelsDeltaY_new > m_fScaleY * 37.5f )
    {
        m_fLabelsDeltaY_new = m_fLabelsDeltaY_new - m_fScaleY * 75.0f;
    }

    if ( m_fLabelsDeltaY_new < 0.0f && m_fAltitude > fAlt2 )
    {
        fAlt1 += 100.0f;
        fAlt2 += 100.0f;
        fAlt3 += 100.0f;
    }

    m_pItemLabel1->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel2->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel3->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );

    if ( fAlt1 > 0.0f && fAlt1 <= 100000.0f )
    {
        m_pItemLabel1->setVisible( true );
        m_pItemLabel1->setPlainText( QString("%1").arg(fAlt1, 5, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel1->setVisible( false );
    }

    if ( fAlt2 > 0.0f && fAlt2 <= 100000.0f )
    {
        m_pItemLabel2->setVisible( true );
        m_pItemLabel2->setPlainText( QString("%1").arg(fAlt2, 5, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel2->setVisible( false );
    }

    if ( fAlt3 > 0.0f && fAlt3 <= 100000.0f )
    {
        m_pItemLabel3->setVisible( true );
        m_pItemLabel3->setPlainText( QString("%1").arg(fAlt3, 5, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel3->setVisible( false );
    }
}

//##############################################################################
//##############################################################################
//##############################################################################

qfi_PFD::ASI::ASI( QGraphicsScene * pScene ) :
    m_pScene ( pScene ),

    m_pItemBack     ( 0 ),
    m_pItemScale1   ( 0 ),
    m_pItemScale2   ( 0 ),
    m_pItemLabel1   ( 0 ),
    m_pItemLabel2   ( 0 ),
    m_pItemLabel3   ( 0 ),
    m_pItemLabel4   ( 0 ),
    m_pItemLabel5   ( 0 ),
    m_pItemLabel6   ( 0 ),
    m_pItemLabel7   ( 0 ),
    m_pItemFrame    ( 0 ),
    m_pItemAirspeed ( 0 ),
    m_pItemMachNo   ( 0 ),

    m_FrameTextColor ( 255, 255, 255 ),
    m_LabelsColor    ( 255, 255, 255 ),

    m_fAirspeed ( 0.0f ),
    m_fMachNo   ( 0.0f ),

    m_fScale1DeltaY_new ( 0.0f ),
    m_fScale1DeltaY_old ( 0.0f ),
    m_fScale2DeltaY_new ( 0.0f ),
    m_fScale2DeltaY_old ( 0.0f ),
    m_fLabelsDeltaY_new ( 0.0f ),
    m_fLabelsDeltaY_old ( 0.0f ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_fOriginalPixPerSpd   (   1.5f ),
    m_fOriginalScaleHeight ( 300.0f ),
    m_fOriginalLabelsX     (  29.0f ),
    m_fOriginalLabel1Y     (  35.0f ),
    m_fOriginalLabel2Y     (  65.0f ),
    m_fOriginalLabel3Y     (  95.0f ),
    m_fOriginalLabel4Y     ( 125.0f ),
    m_fOriginalLabel5Y     ( 155.0f ),
    m_fOriginalLabel6Y     ( 185.0f ),
    m_fOriginalLabel7Y     ( 215.0f ),

    m_OriginalBackPos     ( 15.0f ,   50.0f ),
    m_OriginalScale1Pos   ( 43.0f , -174.5f ),
    m_OriginalScale2Pos   ( 43.0f , -474.5f ),
    m_OriginalFramePos    ( 14.5f ,  117.0f ),
    m_OriginalAirspeedCtr ( 25.0f ,  125.0f ),
    m_OriginalMachNoCtr   ( 65.0f ,  125.0f ),

    m_iBackZ      (  60 ),
    m_iScaleZ     (  70 ),
    m_iLabelsZ    (  70 ),
    m_iFrameZ     ( 110 ),
    m_iFrameTextZ ( 120 )
{
#   ifdef WIN32
    m_FrameTextFont.setFamily( "courier" );
    m_FrameTextFont.setPointSizeF( 7.0f );
    m_FrameTextFont.setStretch( QFont::Condensed );
    m_FrameTextFont.setWeight( QFont::Bold );
#   else
    m_FrameTextFont.setFamily( "courier" );
    m_FrameTextFont.setPointSizeF( 9.0f );
    m_FrameTextFont.setStretch( QFont::Condensed );
    m_FrameTextFont.setWeight( QFont::Bold );
#   endif

    m_LabelsFont.setFamily( "courier" );
    m_LabelsFont.setPointSizeF( 7.0f );
    m_LabelsFont.setStretch( QFont::Condensed );
    m_LabelsFont.setWeight( QFont::Bold );

    reset();
}

//##############################################################################

void qfi_PFD::ASI::init( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    reset();

    m_pItemBack = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_asi_back.svg" );
    m_pItemBack->setCacheMode( QGraphicsItem::NoCache );
    m_pItemBack->setZValue( m_iBackZ );
    m_pItemBack->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemBack->moveBy( m_fScaleX * m_OriginalBackPos.x(), m_fScaleY * m_OriginalBackPos.y() );
    m_pScene->addItem( m_pItemBack );

    m_pItemScale1 = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_asi_scale.svg" );
    m_pItemScale1->setCacheMode( QGraphicsItem::NoCache );
    m_pItemScale1->setZValue( m_iScaleZ );
    m_pItemScale1->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemScale1->moveBy( m_fScaleX * m_OriginalScale1Pos.x(), m_fScaleY * m_OriginalScale1Pos.y() );
    m_pScene->addItem( m_pItemScale1 );

    m_pItemScale2 = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_asi_scale.svg" );
    m_pItemScale2->setCacheMode( QGraphicsItem::NoCache );
    m_pItemScale2->setZValue( m_iScaleZ );
    m_pItemScale2->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemScale2->moveBy( m_fScaleX * m_OriginalScale2Pos.x(), m_fScaleY * m_OriginalScale2Pos.y() );
    m_pScene->addItem( m_pItemScale2 );

    m_pItemLabel1 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel1->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel1->setZValue( m_iLabelsZ );
    m_pItemLabel1->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel1->setFont( m_LabelsFont );
    m_pItemLabel1->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel1->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel1->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel1Y - m_pItemLabel1->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel1 );

    m_pItemLabel2 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel2->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel2->setZValue( m_iLabelsZ );
    m_pItemLabel2->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel2->setFont( m_LabelsFont );
    m_pItemLabel2->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel2->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel2->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel2Y - m_pItemLabel2->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel2 );

    m_pItemLabel3 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel3->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel3->setZValue( m_iLabelsZ );
    m_pItemLabel3->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel3->setFont( m_LabelsFont );
    m_pItemLabel3->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel3->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel3->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel3Y - m_pItemLabel3->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel3 );

    m_pItemLabel4 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel4->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel4->setZValue( m_iLabelsZ );
    m_pItemLabel4->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel4->setFont( m_LabelsFont );
    m_pItemLabel4->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel4->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel4->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel4Y - m_pItemLabel4->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel4 );

    m_pItemLabel5 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel5->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel5->setZValue( m_iLabelsZ );
    m_pItemLabel5->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel5->setFont( m_LabelsFont );
    m_pItemLabel5->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel5->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel5->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel5Y - m_pItemLabel5->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel5 );

    m_pItemLabel6 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel6->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel6->setZValue( m_iLabelsZ );
    m_pItemLabel6->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel6->setFont( m_LabelsFont );
    m_pItemLabel6->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel6->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel6->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel6Y - m_pItemLabel6->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel6 );

    m_pItemLabel7 = new QGraphicsTextItem( QString( "999" ) );
    m_pItemLabel7->setCacheMode( QGraphicsItem::NoCache );
    m_pItemLabel7->setZValue( m_iLabelsZ );
    m_pItemLabel7->setDefaultTextColor( m_LabelsColor );
    m_pItemLabel6->setFont( m_LabelsFont );
    m_pItemLabel7->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemLabel7->moveBy( m_fScaleX * ( m_fOriginalLabelsX - m_pItemLabel7->boundingRect().width()  / 2.0f ),
                           m_fScaleY * ( m_fOriginalLabel7Y - m_pItemLabel7->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemLabel7 );

    m_pItemFrame = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_asi_frame.svg" );
    m_pItemFrame->setCacheMode( QGraphicsItem::NoCache );
    m_pItemFrame->setZValue( m_iFrameZ );
    m_pItemFrame->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemFrame->moveBy( m_fScaleX * m_OriginalFramePos.x(), m_fScaleY * m_OriginalFramePos.y() );
    m_pScene->addItem( m_pItemFrame );

    m_pItemAirspeed = new QGraphicsTextItem( QString( "000" ) );
    m_pItemAirspeed->setCacheMode( QGraphicsItem::NoCache );
    m_pItemAirspeed->setZValue( m_iFrameTextZ );
    m_pItemAirspeed->setTextInteractionFlags( Qt::NoTextInteraction );
    m_pItemAirspeed->setDefaultTextColor( m_FrameTextColor );
    m_pItemAirspeed->setFont( m_FrameTextFont );

    m_pItemAirspeed->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemAirspeed->moveBy( m_fScaleX * ( m_OriginalAirspeedCtr.x() - m_pItemAirspeed->boundingRect().width()  / 2.0f )+10,
                             m_fScaleY * ( m_OriginalAirspeedCtr.y() - m_pItemAirspeed->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemAirspeed );

    m_pItemMachNo = new QGraphicsTextItem( QString( "000" ) );
    m_pItemMachNo->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMachNo->setZValue( m_iFrameTextZ );
    m_pItemMachNo->setTextInteractionFlags( Qt::NoTextInteraction );
    m_pItemMachNo->setDefaultTextColor( m_FrameTextColor );
    m_pItemMachNo->setFont( m_FrameTextFont );
    m_pItemMachNo->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemMachNo->moveBy( m_fScaleX * ( m_OriginalMachNoCtr.x() - m_pItemMachNo->boundingRect().width()  / 2.0f )-25,
                           m_fScaleY * ( m_OriginalMachNoCtr.y() - m_pItemMachNo->boundingRect().height() / 2.0f )+100 );
    m_pScene->addItem( m_pItemMachNo );

    m_HeightMark = new QGraphicsTextItem( QString( "VD" ) );
    m_HeightMark->setCacheMode( QGraphicsItem::NoCache );
    m_HeightMark->setZValue( m_iFrameTextZ );
    m_HeightMark->setTextInteractionFlags( Qt::NoTextInteraction );
    m_HeightMark->setDefaultTextColor(QColor(0,255,0));
    m_HeightMark->setFont( m_FrameTextFont );
    m_HeightMark->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_HeightMark->moveBy( m_fScaleX * ( m_OriginalMachNoCtr.x() - m_pItemMachNo->boundingRect().width()  / 2.0f )-18,
                           m_fScaleY * ( m_OriginalMachNoCtr.y() - m_pItemMachNo->boundingRect().height() / 2.0f )-100 );
    m_pScene->addItem( m_HeightMark );

    update( fScaleX, fScaleY );
}

//##############################################################################

void qfi_PFD::ASI::update( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    updateAirspeed();

    m_fScale1DeltaY_old = m_fScale1DeltaY_new;
    m_fScale2DeltaY_old = m_fScale2DeltaY_new;
    m_fLabelsDeltaY_old = m_fLabelsDeltaY_new;
}

//##############################################################################

void qfi_PFD::ASI::setAirspeed( float fAirspeed )
{
    m_fAirspeed = fAirspeed;

    if ( m_fAirspeed <    0.0f ) m_fAirspeed =    0.0f;
    if ( m_fAirspeed > 9999.0f ) m_fAirspeed = 9999.0f;
}

//##############################################################################

void qfi_PFD::ASI::setMachNo( float fMachNo )
{
    m_fMachNo = fMachNo;

    if ( m_fMachNo <  0.0f ) m_fMachNo =  0.0f;
    if ( m_fMachNo > 99.9f ) m_fMachNo = 99.9f;
}

//##############################################################################

void qfi_PFD::ASI::reset()
{
    m_pItemBack     = 0;
    m_pItemScale1   = 0;
    m_pItemScale2   = 0;
    m_pItemLabel1   = 0;
    m_pItemLabel2   = 0;
    m_pItemLabel3   = 0;
    m_pItemLabel4   = 0;
    m_pItemLabel5   = 0;
    m_pItemLabel6   = 0;
    m_pItemLabel7   = 0;
    m_pItemFrame    = 0;
    m_pItemAirspeed = 0;
    m_pItemMachNo   = 0;

    m_fAirspeed = 0.0f;
    m_fMachNo   = 0.0f;

    m_fScale1DeltaY_new = 0.0f;
    m_fScale1DeltaY_old = 0.0f;
    m_fScale2DeltaY_new = 0.0f;
    m_fScale2DeltaY_old = 0.0f;
    m_fLabelsDeltaY_new = 0.0f;
    m_fLabelsDeltaY_old = 0.0f;
}

//##############################################################################

void qfi_PFD::ASI::updateAirspeed()
{
    m_pItemAirspeed->setPlainText( QString("%1").arg(m_fAirspeed, 3, 'f', 0, QChar('0')) );

    if ( m_fMachNo < 1.0f )
    {
        float dMachNo = 1000.0f * m_fMachNo;
        m_pItemMachNo->setPlainText( QString("%1").arg(dMachNo, 3, 'f', 0, QChar('0')) );
    }
    else
    {
        if ( m_fMachNo < 10.0f )
        {
            m_pItemMachNo->setPlainText( QString::number( m_fMachNo, 'f', 2 ) );
        }
        else
        {
            m_pItemMachNo->setPlainText( QString::number( m_fMachNo, 'f', 1 ) );
        }
    }

    updateScale();
    updateScaleLabels();
}

//##############################################################################

void qfi_PFD::ASI::updateScale()
{
    m_fScale1DeltaY_new = m_fScaleY * m_fOriginalPixPerSpd * m_fAirspeed;
    m_fScale2DeltaY_new = m_fScale1DeltaY_new;

    float fScaleSingleHeight = m_fScaleY * m_fOriginalScaleHeight;
    float fScalefloatHeight = m_fScaleY * m_fOriginalScaleHeight * 2.0f;

    while ( m_fScale1DeltaY_new > fScaleSingleHeight + m_fScaleY * 74.5f )
    {
        m_fScale1DeltaY_new = m_fScale1DeltaY_new - fScalefloatHeight;
    }

    while ( m_fScale2DeltaY_new > fScalefloatHeight + m_fScaleY * 74.5f )
    {
        m_fScale2DeltaY_new = m_fScale2DeltaY_new - fScalefloatHeight;
    }

    m_pItemScale1->moveBy( 0.0f, m_fScale1DeltaY_new - m_fScale1DeltaY_old );
    m_pItemScale2->moveBy( 0.0f, m_fScale2DeltaY_new - m_fScale2DeltaY_old );
}

//##############################################################################

void qfi_PFD::ASI::updateScaleLabels()
{
    m_fLabelsDeltaY_new = m_fScaleY * m_fOriginalPixPerSpd * m_fAirspeed;

    int iTmp = floor( m_fAirspeed + 0.5f );
    int iSpd = iTmp - ( iTmp % 20 );

    float fSpd1 = (float)iSpd + 60.0f;
    float fSpd2 = (float)iSpd + 40.0f;
    float fSpd3 = (float)iSpd + 20.0f;
    float fSpd4 = (float)iSpd;
    float fSpd5 = (float)iSpd - 20.0f;
    float fSpd6 = (float)iSpd - 40.0f;
    float fSpd7 = (float)iSpd - 60.0f;

    while ( m_fLabelsDeltaY_new > m_fScaleY * 15.0f )
    {
        m_fLabelsDeltaY_new = m_fLabelsDeltaY_new - m_fScaleY * 30.0f;
    }

    if ( m_fLabelsDeltaY_new < 0.0f && m_fAirspeed > fSpd4 )
    {
        fSpd1 += 20.0f;
        fSpd2 += 20.0f;
        fSpd3 += 20.0f;
        fSpd4 += 20.0f;
        fSpd5 += 20.0f;
        fSpd6 += 20.0f;
        fSpd7 += 20.0f;
    }

    m_pItemLabel1->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel2->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel3->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel4->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel5->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel6->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );
    m_pItemLabel7->moveBy( 0.0f, m_fLabelsDeltaY_new - m_fLabelsDeltaY_old );

    if ( fSpd1 >= 0.0f && fSpd1 <= 10000.0f )
    {
        m_pItemLabel1->setVisible( true );
        m_pItemLabel1->setPlainText( QString("%1").arg(fSpd1, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel1->setVisible( false );
    }

    if ( fSpd2 >= 0.0f && fSpd2 <= 10000.0f )
    {
        m_pItemLabel2->setVisible( true );
        m_pItemLabel2->setPlainText( QString("%1").arg(fSpd2, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel2->setVisible( false );
    }

    if ( fSpd3 >= 0.0f && fSpd3 <= 10000.0f )
    {
        m_pItemLabel3->setVisible( true );
        m_pItemLabel3->setPlainText( QString("%1").arg(fSpd3, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel3->setVisible( false );
    }

    if ( fSpd4 >= 0.0f && fSpd4 <= 10000.0f )
    {
        m_pItemLabel4->setVisible( true );
        m_pItemLabel4->setPlainText( QString("%1").arg(fSpd4, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel4->setVisible( false );
    }

    if ( fSpd5 >= 0.0f && fSpd5 <= 10000.0f )
    {
        m_pItemLabel5->setVisible( true );
        m_pItemLabel5->setPlainText( QString("%1").arg(fSpd5, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel5->setVisible( false );
    }

    if ( fSpd6 >= 0.0f && fSpd6 <= 10000.0f )
    {
        m_pItemLabel6->setVisible( true );
        m_pItemLabel6->setPlainText( QString("%1").arg(fSpd6, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel6->setVisible( false );
    }

    if ( fSpd7 >= 0.0f && fSpd7 <= 10000.0f )
    {
        m_pItemLabel7->setVisible( true );
        m_pItemLabel7->setPlainText( QString("%1").arg(fSpd7, 3, 'f', 0, QChar(' ')) );
    }
    else
    {
        m_pItemLabel7->setVisible( false );
    }
}

//##############################################################################
//##############################################################################
//##############################################################################

qfi_PFD::HSI::HSI( QGraphicsScene * pScene ) :
    m_pScene ( pScene ),

    m_pItemTurn      ( 0 ),
    m_pItemTurnMaskL ( 0 ),
    m_pItemTurnMaskR ( 0 ),
    m_pItemFace      ( 0 ),
    m_pItemMarks     ( 0 ),
    m_pItemFrameText ( 0 ),

    m_FrameTextColor ( 255, 255, 255 ),

    m_fHeading  ( 0.0f ),
    m_fTurnRate ( 0.0f ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_fDegPerDegPerSec ( 6.0f ),

    m_OriginalHsiCtr       ( 150.0f , 399.0f ),
    m_OriginalTurnPos      (  34.0f,  225.5f ),
    m_OriginalTurnMaskLPos (  27.0f,  225.5f ),
    m_OriginalTurnMaskRPos ( 150.0f,  225.5f ),
    m_OriginalFacePos      ( -20.0f , 250.0f ),
    m_OriginalMarksPos     (  29.5f , 229.0f ),
    m_OriginalFrameTextCtr ( 149.5f , 245.5f ),

    m_iTurnZ      ( 110 ),
    m_iTurnMaskZ  ( 120 ),
    m_iFaceZ      ( 130 ),
    m_iMarksZ     ( 130 ),
    m_iFrameTextZ ( 140 )
{
    m_FrameTextFont.setFamily( "courier" );
    m_FrameTextFont.setPointSizeF( 10.0f );
    m_FrameTextFont.setStretch( QFont::Condensed );
    m_FrameTextFont.setWeight( QFont::Bold );

    reset();
}

//##############################################################################

void qfi_PFD::HSI::init( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    reset();

    m_pItemTurn = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_hsi_turn.svg" );
    m_pItemTurn->setCacheMode( QGraphicsItem::NoCache );
    m_pItemTurn->setZValue( m_iTurnZ );
    m_pItemTurn->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemTurn->moveBy( m_fScaleX * m_OriginalTurnPos.x(), m_fScaleY * m_OriginalTurnPos.y() );
    m_pScene->addItem( m_pItemTurn );

    m_pItemTurnMaskL = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_hsi_turn_l.svg" );
    m_pItemTurnMaskL->setCacheMode( QGraphicsItem::NoCache );
    m_pItemTurnMaskL->setZValue( m_iTurnMaskZ );
    m_pItemTurnMaskL->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemTurnMaskL->setTransformOriginPoint( m_OriginalHsiCtr - m_OriginalTurnMaskLPos );
    m_pItemTurnMaskL->moveBy( m_fScaleX * m_OriginalTurnMaskLPos.x(), m_fScaleY * m_OriginalTurnMaskLPos.y() );
    m_pScene->addItem( m_pItemTurnMaskL );

    m_pItemTurnMaskR = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_hsi_turn_r.svg" );
    m_pItemTurnMaskR->setCacheMode( QGraphicsItem::NoCache );
    m_pItemTurnMaskR->setZValue( m_iTurnMaskZ );
    m_pItemTurnMaskR->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemTurnMaskR->setTransformOriginPoint( m_OriginalHsiCtr - m_OriginalTurnMaskRPos );
    m_pItemTurnMaskR->moveBy( m_fScaleX * m_OriginalTurnMaskRPos.x(), m_fScaleY * m_OriginalTurnMaskRPos.y() );
    m_pScene->addItem( m_pItemTurnMaskR );

    m_pItemFace = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_hsi_face.svg" );
    m_pItemFace->setCacheMode( QGraphicsItem::NoCache );
    m_pItemFace->setZValue( m_iFaceZ );
    m_pItemFace->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemFace->setTransformOriginPoint( m_OriginalHsiCtr - m_OriginalFacePos );
    m_pItemFace->moveBy( m_fScaleX * m_OriginalFacePos.x(), m_fScaleY * m_OriginalFacePos.y() );
    m_pScene->addItem( m_pItemFace );

    m_pItemMarks = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_hsi_marks.svg" );
    m_pItemMarks->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMarks->setZValue( m_iMarksZ );
    m_pItemMarks->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemMarks->moveBy( m_fScaleX * m_OriginalMarksPos.x(), m_fScaleY * m_OriginalMarksPos.y() );
    m_pScene->addItem( m_pItemMarks );

    m_pItemFrameText = new QGraphicsTextItem( QString( "000" ) );
    m_pItemFrameText->setCacheMode( QGraphicsItem::NoCache );
    m_pItemFrameText->setZValue( m_iFrameTextZ );
    m_pItemFrameText->setTextInteractionFlags( Qt::NoTextInteraction );
    m_pItemFrameText->setDefaultTextColor( m_FrameTextColor );
    m_pItemFrameText->setFont( m_FrameTextFont );
    m_pItemFrameText->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemFrameText->moveBy( m_fScaleX * ( m_OriginalFrameTextCtr.x() - m_pItemFrameText->boundingRect().width()  / 2.0f ),
                              m_fScaleY * ( m_OriginalFrameTextCtr.y() - m_pItemFrameText->boundingRect().height() / 2.0f ) );
    m_pScene->addItem( m_pItemFrameText );

    update( fScaleX, fScaleY );
}

//##############################################################################

void qfi_PFD::HSI::update( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    updateHeading();
    updateTurnRate();
}

//##############################################################################

void qfi_PFD::HSI::setHeading( float fHeading )
{
    m_fHeading = fHeading;

    if ( m_fHeading < 0.0f )
    {
        m_fHeading = 0.0f;
    }

    if ( m_fHeading > 360.0f )
    {
        m_fHeading = 360.0f;
    }
}

//##############################################################################

void qfi_PFD::HSI::setTurnRate( float fTurnRate )
{
    m_fTurnRate = fTurnRate;

    if ( m_fTurnRate < -7.0f ) m_fTurnRate = -7.0f;
    if ( m_fTurnRate >  7.0f ) m_fTurnRate =  7.0f;
}

//##############################################################################

void qfi_PFD::HSI::reset()
{
    m_pItemTurn      = 0;
    m_pItemTurnMaskL = 0;
    m_pItemTurnMaskR = 0;
    m_pItemFace      = 0;
    m_pItemMarks     = 0;
    m_pItemFrameText = 0;

    m_fHeading  = 0.0f;
    m_fTurnRate = 0.0f;
}

//##############################################################################

void qfi_PFD::HSI::updateHeading()
{
    m_pItemFace->setRotation( - m_fHeading );

    float fHeading = floor( m_fHeading + 0.5f );

    m_pItemFrameText->setPlainText( QString("%1").arg(fHeading, 3, 'f', 0, QChar('0')) );
}

//##############################################################################

void qfi_PFD::HSI::updateTurnRate()
{
    m_pItemTurnMaskL->setRotation( 0.0f );
    m_pItemTurnMaskR->setRotation( 0.0f );

    if ( m_fTurnRate < 0.0 )
    {
        m_pItemTurnMaskL->setRotation( m_fTurnRate * m_fDegPerDegPerSec );
    }

    if ( m_fTurnRate > 0.0 )
    {
        m_pItemTurnMaskR->setRotation( m_fTurnRate * m_fDegPerDegPerSec );
    }
}

//##############################################################################
//##############################################################################
//##############################################################################

qfi_PFD::VSI::VSI( QGraphicsScene * pScene ) :
    m_pScene ( pScene ),

    m_pItemScale   ( 0 ),
    m_pItemMarker  ( 0 ),
    m_pItemMarkerC ( 0 ),
    m_pItemMarkerD ( 0 ),

    m_fClimbRate ( 0.0 ),

    m_fMarkerDeltaY_new ( 0.0 ),
    m_fMarkerDeltaY_old ( 0.0 ),
    m_fMarkerScaleY_new ( 1.0 ),
    m_fMarkerScaleY_old ( 1.0 ),

    m_fScaleX ( 1.0f ),
    m_fScaleY ( 1.0f ),

    m_fOriginalMarkeHeight ( 75.0f ),
    m_fOriginalPixPerSpd1  ( 36.0f ),
    m_fOriginalPixPerSpd2  ( 18.0f ),
    m_fOriginalPixPerSpd4  ( 10.0f ),

    m_OriginalScalePos  ( 275.0f ,  45.0f ),
    m_OriginalMarkerPos ( 283.0f , 125.5f ),
    m_OriginalMarkerCPos ( 282.0f ,  46.5f ),
    m_OriginalMarkerDPos ( 282.0f , 195.5f ),

    m_iScaleZ  ( 110 ),
    m_iMarkerZ ( 120 )
{
    reset();
}

//##############################################################################

void qfi_PFD::VSI::init( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    reset();

    m_pItemScale = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_vsi_scale.svg" );
    m_pItemScale->setCacheMode( QGraphicsItem::NoCache );
    m_pItemScale->setZValue( m_iScaleZ );
    m_pItemScale->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemScale->moveBy( m_fScaleX * m_OriginalScalePos.x(), m_fScaleY * m_OriginalScalePos.y() );
    m_pScene->addItem( m_pItemScale );

    m_pItemMarker = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_vsi_marker.svg" );
    m_pItemMarker->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMarker->setZValue( m_iMarkerZ );
    m_pItemMarker->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemMarker->moveBy( m_fScaleX * m_OriginalMarkerPos.x(), m_fScaleY * m_OriginalMarkerPos.y() );
    m_pScene->addItem( m_pItemMarker );

    m_pItemMarkerC = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_vsi_marker_c.svg" );
    m_pItemMarkerC->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMarkerC->setZValue( m_iMarkerZ );
    m_pItemMarkerC->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemMarkerC->moveBy( m_fScaleX * m_OriginalMarkerCPos.x(), m_fScaleY * m_OriginalMarkerCPos.y() );
    m_pScene->addItem( m_pItemMarkerC );

    m_pItemMarkerD = new QGraphicsSvgItem( ":/qfi/images/pfd/pfd_vsi_marker_d.svg" );
    m_pItemMarkerD->setCacheMode( QGraphicsItem::NoCache );
    m_pItemMarkerD->setZValue( m_iMarkerZ );
    m_pItemMarkerD->setTransform(QTransform::fromScale(m_fScaleX, m_fScaleY), true);
    m_pItemMarkerD->moveBy( m_fScaleX * m_OriginalMarkerDPos.x(), m_fScaleY * m_OriginalMarkerDPos.y() );
    m_pScene->addItem( m_pItemMarkerD );

    update( fScaleX, fScaleY );
}



//##############################################################################

void qfi_PFD::VSI::update( float fScaleX, float fScaleY )
{
    m_fScaleX = fScaleX;
    m_fScaleY = fScaleY;

    updateClimbRate();

    m_fMarkerDeltaY_old = m_fMarkerDeltaY_new;
    m_fMarkerScaleY_old = m_fMarkerScaleY_new;
}

//##############################################################################

void qfi_PFD::VSI::setClimbRate( float fClimbRate )
{
    m_fClimbRate = fClimbRate;

    if ( m_fClimbRate >  4.0f ) m_fClimbRate =  4.0f;
    if ( m_fClimbRate < -4.0f ) m_fClimbRate = -4.0f;
}

//##############################################################################

void qfi_PFD::VSI::reset()
{
    m_pItemScale   = 0;
    m_pItemMarker  = 0;
    m_pItemMarkerC = 0;
    m_pItemMarkerD = 0;

    m_fClimbRate = 0.0f;

    m_fMarkerDeltaY_new = 0.0f;
    m_fMarkerDeltaY_old = 0.0f;
    m_fMarkerScaleY_new = 1.0f;
    m_fMarkerScaleY_old = 1.0f;
}

//##############################################################################

void qfi_PFD::VSI::updateClimbRate()
{
    float fMarkerHeight = 0.0f;

    float fClimbRateAbs = fabs( m_fClimbRate );

    if ( fClimbRateAbs <= 1.0f )
    {
        fMarkerHeight = m_fOriginalPixPerSpd1 * fClimbRateAbs;
    }
    else if ( fClimbRateAbs <= 2.0f )
    {
        fMarkerHeight = m_fOriginalPixPerSpd1 + m_fOriginalPixPerSpd2 * ( fClimbRateAbs - 1.0f );
    }
    else
    {
        fMarkerHeight = m_fOriginalPixPerSpd1 + m_fOriginalPixPerSpd2 + m_fOriginalPixPerSpd4 * ( fClimbRateAbs - 2.0f );
    }

    m_fMarkerScaleY_new = ( (fMarkerHeight < 0.1f) ? 0.1f : fMarkerHeight ) / m_fOriginalMarkeHeight;

    //m_pItemMarker->scale( 1.0f, m_fMarkerScaleY_new / m_fMarkerScaleY_old );



    if ( m_fClimbRate > 0.0f )
    {
        m_fMarkerDeltaY_new = m_fScaleY * ( fMarkerHeight + 1.0f );
    }
    else
    {
        m_fMarkerDeltaY_new = 0.0f;
    }

    m_pItemMarker->moveBy( 0.0f, m_fMarkerDeltaY_old - m_fMarkerDeltaY_new );

    if ( m_fClimbRate <= -4.0f )
    {
        m_pItemMarkerD->setVisible( true );
    }
    else
    {
        m_pItemMarkerD->setVisible( false );
    }

    if ( m_fClimbRate >= 4.0f )
    {
        m_pItemMarkerC->setVisible( true );
    }
    else
    {
        m_pItemMarkerC->setVisible( false );
    }

}
