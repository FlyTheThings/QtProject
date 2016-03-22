/***************************************************************************//**
 * @file qfi_PFD.h
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
#ifndef _QFI_PFD_H_
#define _QFI_PFD_H_

//##############################################################################

#include <QGraphicsView>
#include <QGraphicsSvgItem>

//##############################################################################

/** This is Primary Flight Display widget. Please notice that unlike other QFI
 * instruments widget this one does not use any specific units except for
 * attitude, heading [degrees] and turn rate [degrees per second]. */
class qfi_PFD : public QGraphicsView
{
    Q_OBJECT

public:

    /** Constructor. */
    qfi_PFD( QWidget * pParent = 0 );

    /** Destructor. */
    virtual ~qfi_PFD();

    /** This function reinitiate widget. */
    void reinit();

    /** You need to call this function to refresh (redraw) widget. */
    void update();

    /** @param fRoll [deg] */
    inline void setRoll( float fRoll )
    {
        m_pADI->setRoll( fRoll );
    }

    /** @param fPitch [deg] */
    inline void setPitch( float fPitch )
    {
        m_pADI->setPitch( fPitch );
    }

    /** @param fSideSlip -1.0 ... 1.0 */
    inline void setSideSlip( float fSideSlip )
    {
        m_pADI->setSideSlip( fSideSlip );
    }

    /** @param fIlsGs -1.0 ... 1.0
     * @param iIlsGs ILS glide slope bar visibility */
    inline void setIlsGs( float fIlsGs, int iIlsGs = 1 )
    {
        m_pADI->setIlsGs( fIlsGs, iIlsGs );
    }

    /** @param fIlsLc -1.0 ... 1.0
     * @param iIlsGs ILS localizer bar visibility */
    inline void setIlsLc( float fIlsLc, int iIlsLc = 1 )
    {
        m_pADI->setIlsLc( fIlsLc, iIlsLc );
    }

    /** @param fAltitude [altitude units] */
    inline void setAltitude( float fAltitude )
    {
        m_pALT->setAltitude( fAltitude );
    }

    /** @param fPressure [pressure units] */
    inline void setPressure( float fPressure )
    {
        m_pALT->setPressure( fPressure );
    }

    /** @param fAirspeed [airspeed units] */
    inline void setAirspeed( float fAirspeed )
    {
        m_pASI->setAirspeed( fAirspeed );
    }

    /** @param fMachNo [-] */
    inline void setMachNo( float fMachNo )
    {
        m_pASI->setMachNo( fMachNo );
    }

    /** @param fHeading [deg] */
    inline void setHeading( float fHeading )
    {
        m_pHSI->setHeading( fHeading );
    }

    /** @param fTurnRate [deg/s] */
    inline void setTurnRate( float fTurnRate )
    {
        m_pHSI->setTurnRate( fTurnRate );
    }

    /** @param fClimbRate [climb rate units] */
    inline void setClimbRate( float fClimbRate )
    {
        m_pVSI->setClimbRate( fClimbRate );
    }

protected:

    /** */
    void resizeEvent( QResizeEvent * pEvent );

private:

    /** */
    class ADI
    {
    public:

        ADI( QGraphicsScene * pScene );

        void init( float fScaleX, float fScaleY );
        void update( float fScaleX, float fScaleY );

        void setRoll( float fRoll );
        void setPitch( float fPitch );
        void setSideSlip( float fSideSlip );
        void setIlsGs( float fIlsGs, int iIlsGs = 1 );
        void setIlsLc( float fIlsLc, int iIlsLc = 1 );

    private:

        QGraphicsScene * m_pScene;

        QGraphicsSvgItem  * m_pItemLadd;
        QGraphicsSvgItem  * m_pItemRoll;
        QGraphicsSvgItem  * m_pItemSlip;
        QGraphicsSvgItem  * m_pItemIlsGs;
        QGraphicsSvgItem  * m_pItemIlsLc;
        QGraphicsSvgItem  * m_pItemMask;
        QGraphicsTextItem  * m_pItemDispitch;
        QGraphicsTextItem  * m_pItemDisRoll;

        float m_fRoll;
        float m_fPitch;
        float m_fSideSlip;
        float m_fIlsGs;
        float m_fIlsLc;

        int m_iIlsGs;
        int m_iIlsLc;

        float m_fLaddDeltaX_new;
        float m_fLaddDeltaX_old;
        float m_fLaddDeltaY_new;
        float m_fLaddDeltaY_old;
        float m_fSlipDeltaX_new;
        float m_fSlipDeltaX_old;
        float m_fIlsLcDeltaX_new;
        float m_fIlsLcDeltaX_old;
        float m_fIlsGsDeltaY_new;
        float m_fIlsGsDeltaY_old;

        float m_fScaleX;
        float m_fScaleY;

        const float m_fOriginalPixPerDeg;
        const float m_fMaxSlipDeflection;
        const float m_fMaxIlsDeflection;

        QPointF m_OriginalAdiCtr;
        QPointF m_OriginalLaddPos;
        QPointF m_OriginalRollPos;
        QPointF m_OriginalSlipPos;
        QPointF m_OriginalIlsGsPos;
        QPointF m_OriginalIlsLcPos;

        const int m_iLaddZ;
        const int m_iRollZ;
        const int m_iSlipZ;
        const int m_iIls_Z;
        const int m_iMaskZ;

        void reset();

        void updateLadd();
        void updateRoll();
        void updateSideSlip();
        void updateIls();
    };

    /** */
    class ALT
    {
    public:

        ALT( QGraphicsScene * pScene );

        void init( float fScaleX, float fScaleY );
        void update( float fScaleX, float fScaleY );

        void setAltitude( float fAltitude );
        void setPressure( float fPressure );

    private:

        QGraphicsScene * m_pScene;

        QGraphicsSvgItem  * m_pItemBack;
        QGraphicsSvgItem  * m_pItemScale1;
        QGraphicsSvgItem  * m_pItemScale2;
        QGraphicsTextItem * m_pItemLabel1;
        QGraphicsTextItem * m_pItemLabel2;
        QGraphicsTextItem * m_pItemLabel3;
        QGraphicsSvgItem  * m_pItemGround;
        QGraphicsSvgItem  * m_pItemFrame;
        QGraphicsTextItem * m_pItemAltitude;
        QGraphicsTextItem * m_pItemPressure;
        QGraphicsTextItem * m_SpeedMark;

        QColor m_FrameTextColor;
        QColor m_PressTextColor;
        QColor m_LabelsColor;

        QFont  m_FrameTextFont;
        QFont  m_PressTextFont;
        QFont  m_LabelsFont;

        float m_fAltitude;
        float m_fPressure;

        float m_fScale1DeltaY_new;
        float m_fScale1DeltaY_old;
        float m_fScale2DeltaY_new;
        float m_fScale2DeltaY_old;
        float m_fGroundDeltaY_new;
        float m_fGroundDeltaY_old;
        float m_fLabelsDeltaY_new;
        float m_fLabelsDeltaY_old;

        float m_fScaleX;
        float m_fScaleY;

        const float m_fOriginalPixPerAlt;
        const float m_fOriginalScaleHeight;
        const float m_fOriginalLabelsX;
        const float m_fOriginalLabel1Y;
        const float m_fOriginalLabel2Y;
        const float m_fOriginalLabel3Y;

        QPointF m_OriginalBackPos;
        QPointF m_OriginalScale1Pos;
        QPointF m_OriginalScale2Pos;
        QPointF m_OriginalGroundPos;
        QPointF m_OriginalFramePos;
        QPointF m_OriginalAltitudeCtr;
        QPointF m_OriginalPressureCtr;

        const int m_iBackZ;
        const int m_iScaleZ;
        const int m_iLabelsZ;
        const int m_iGroundZ;
        const int m_iFrameZ;
        const int m_iFrameTextZ;
        const int m_iPressTextZ;

        void reset();

        void updateAltitude();
        void updatePressure();
        void updateScale();
        void updateScaleLabels();
    };

    /** */
    class ASI
    {
    public:

        ASI( QGraphicsScene * pScene );

        void init( float fScaleX, float fScaleY );
        void update( float fScaleX, float fScaleY );

        void setAirspeed( float fAirspeed );
        void setMachNo( float fMachNo );

    private:

        QGraphicsScene * m_pScene;

        QGraphicsSvgItem  * m_pItemBack;
        QGraphicsSvgItem  * m_pItemScale1;
        QGraphicsSvgItem  * m_pItemScale2;
        QGraphicsTextItem * m_pItemLabel1;
        QGraphicsTextItem * m_pItemLabel2;
        QGraphicsTextItem * m_pItemLabel3;
        QGraphicsTextItem * m_pItemLabel4;
        QGraphicsTextItem * m_pItemLabel5;
        QGraphicsTextItem * m_pItemLabel6;
        QGraphicsTextItem * m_pItemLabel7;
        QGraphicsSvgItem  * m_pItemFrame;
        QGraphicsTextItem * m_pItemAirspeed;
        QGraphicsTextItem * m_pItemMachNo;
        QGraphicsTextItem * m_HeightMark;

        QColor m_FrameTextColor;
        QColor m_LabelsColor;

        QFont  m_FrameTextFont;
        QFont  m_LabelsFont;

        float m_fAirspeed;
        float m_fMachNo;

        float m_fScale1DeltaY_new;
        float m_fScale1DeltaY_old;
        float m_fScale2DeltaY_new;
        float m_fScale2DeltaY_old;
        float m_fLabelsDeltaY_new;
        float m_fLabelsDeltaY_old;

        float m_fScaleX;
        float m_fScaleY;

        const float m_fOriginalPixPerSpd;
        const float m_fOriginalScaleHeight;
        const float m_fOriginalLabelsX;
        const float m_fOriginalLabel1Y;
        const float m_fOriginalLabel2Y;
        const float m_fOriginalLabel3Y;
        const float m_fOriginalLabel4Y;
        const float m_fOriginalLabel5Y;
        const float m_fOriginalLabel6Y;
        const float m_fOriginalLabel7Y;

        QPointF m_OriginalBackPos;
        QPointF m_OriginalScale1Pos;
        QPointF m_OriginalScale2Pos;
        QPointF m_OriginalFramePos;
        QPointF m_OriginalAirspeedCtr;
        QPointF m_OriginalMachNoCtr;

        const int m_iBackZ;
        const int m_iScaleZ;
        const int m_iLabelsZ;
        const int m_iFrameZ;
        const int m_iFrameTextZ;

        void reset();

        void updateAirspeed();
        void updateScale();
        void updateScaleLabels();
    };

    /** */
    class HSI
    {
    public:

        HSI( QGraphicsScene * pScene );

        void init( float fScaleX, float fScaleY );
        void update( float fScaleX, float fScaleY );

        void setHeading( float fHeading );
        void setTurnRate( float fTurnRate );

    private:

        QGraphicsScene * m_pScene;

        QGraphicsSvgItem  * m_pItemTurn;
        QGraphicsSvgItem  * m_pItemTurnMaskL;
        QGraphicsSvgItem  * m_pItemTurnMaskR;
        QGraphicsSvgItem  * m_pItemFace;
        QGraphicsSvgItem  * m_pItemMarks;
        QGraphicsTextItem * m_pItemFrameText;

        QColor m_FrameTextColor;

        QFont  m_FrameTextFont;

        float m_fHeading;
        float m_fTurnRate;

        float m_fScaleX;
        float m_fScaleY;

        const float m_fDegPerDegPerSec;

        QPointF m_OriginalHsiCtr;
        QPointF m_OriginalTurnPos;
        QPointF m_OriginalTurnMaskLPos;
        QPointF m_OriginalTurnMaskRPos;
        QPointF m_OriginalFacePos;
        QPointF m_OriginalMarksPos;
        QPointF m_OriginalFrameTextCtr;

        const int m_iTurnZ;
        const int m_iTurnMaskZ;
        const int m_iFaceZ;
        const int m_iMarksZ;
        const int m_iFrameTextZ;

        void reset();

        void updateHeading();
        void updateTurnRate();
    };

    /** */
    class VSI
    {
    public:

        VSI( QGraphicsScene * pScene );

        void init( float fScaleX, float fScaleY );
        void update( float fScaleX, float fScaleY );

        void setClimbRate( float fClimbRate );

    private:

        QGraphicsScene * m_pScene;

        QGraphicsSvgItem  * m_pItemScale;
        QGraphicsSvgItem  * m_pItemMarker;
        QGraphicsSvgItem  * m_pItemMarkerC;
        QGraphicsSvgItem  * m_pItemMarkerD;

        float m_fClimbRate;

        float m_fMarkerDeltaY_new;
        float m_fMarkerDeltaY_old;
        float m_fMarkerScaleY_new;
        float m_fMarkerScaleY_old;

        float m_fScaleX;
        float m_fScaleY;

        const float m_fOriginalMarkeHeight;
        const float m_fOriginalPixPerSpd1;
        const float m_fOriginalPixPerSpd2;
        const float m_fOriginalPixPerSpd4;

        QPointF m_OriginalScalePos;
        QPointF m_OriginalMarkerPos;
        QPointF m_OriginalMarkerCPos;
        QPointF m_OriginalMarkerDPos;

        const int m_iScaleZ;
        const int m_iMarkerZ;

        void reset();

        void updateClimbRate();
    };

    QGraphicsScene * m_pScene;

    ADI * m_pADI;
    ALT * m_pALT;
    ASI * m_pASI;
    HSI * m_pHSI;
    VSI * m_pVSI;

    QGraphicsSvgItem * m_pItemBack;
    QGraphicsSvgItem * m_pItemMask;
    QGraphicsSvgItem * m_pItemLight;
    QGraphicsSvgItem * m_pItemLight2;

    float m_fScaleX;
    float m_fScaleY;

    const int m_iOriginalHeight;
    const int m_iOriginalWidth;

    const int m_iBackZ;
    const int m_iMaskZ;

    void init();

    void reset();

    void updateView();
};

//##############################################################################

#endif // _QFI_PFD_H_
