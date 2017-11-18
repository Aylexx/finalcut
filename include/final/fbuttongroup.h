/***********************************************************************
* fbuttongroup.h - The FButtonGroup widget organizes FToggleButton     *
*                  widgets in a group.                                 *
*                                                                      *
* This file is part of the Final Cut widget toolkit                    *
*                                                                      *
* Copyright 2014-2017 Markus Gans                                      *
*                                                                      *
* The Final Cut is free software; you can redistribute it and/or       *
* modify it under the terms of the GNU Lesser General Public License   *
* as published by the Free Software Foundation; either version 3 of    *
* the License, or (at your option) any later version.                  *
*                                                                      *
* The Final Cut is distributed in the hope that it will be useful,     *
* but WITHOUT ANY WARRANTY; without even the implied warranty of       *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
* GNU Lesser General Public License for more details.                  *
*                                                                      *
* You should have received a copy of the GNU Lesser General Public     *
* License along with this program.  If not, see                        *
* <http://www.gnu.org/licenses/>.                                      *
***********************************************************************/

/*  Inheritance diagram
 *  ═══════════════════
 *
 * ▕▔▔▔▔▔▔▔▔▔▏
 * ▕  FTerm  ▏
 * ▕▁▁▁▁▁▁▁▁▁▏
 *      ▲
 *      │
 * ▕▔▔▔▔▔▔▔▔▔▏ ▕▔▔▔▔▔▔▔▔▔▏
 * ▕ FVTerm  ▏ ▕ FObject ▏
 * ▕▁▁▁▁▁▁▁▁▁▏ ▕▁▁▁▁▁▁▁▁▁▏
 *      ▲           ▲
 *      │           │
 *      └─────┬─────┘
 *            │
 *       ▕▔▔▔▔▔▔▔▔▔▏
 *       ▕ FWidget ▏
 *       ▕▁▁▁▁▁▁▁▁▁▏
 *            ▲
 *            │
 *     ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏
 *     ▕ FButtonGroup ▏
 *     ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏
 */

#ifndef FBUTTONGROUP_H
#define FBUTTONGROUP_H

#if !defined (USE_FINAL_H) && !defined (COMPILE_FINAL_CUT)
  #error "Only <final/final.h> can be included directly."
#endif

#include "final/fscrollview.h"


// class forward declaration
class FToggleButton;

//----------------------------------------------------------------------
// class FButtonGroup
//----------------------------------------------------------------------

#pragma pack(push)
#pragma pack(1)

class FButtonGroup : public FScrollView
{
  public:
    // Constructors
    explicit FButtonGroup (FWidget* = 0);
    FButtonGroup (const FString&, FWidget* = 0);

    // Destructor
    virtual ~FButtonGroup();

    // Accessor
    const char*    getClassName() const;
    FToggleButton* getFirstButton();
    FToggleButton* getLastButton();
    FToggleButton* getButton (int) const;
    uInt           getCount() const;
    FString&       getText();

    // Mutator
    bool           setEnable(bool);
    bool           setEnable();
    bool           unsetEnable();
    bool           setDisable();
    void           setText (const FString&);

    // Inquiries
    bool           isChecked(int) const;
    bool           hasFocusedButton() const;
    bool           hasCheckedButton() const;

    // Methods
    void           hide();
    void           insert (FToggleButton*);
    void           remove (FToggleButton*);
    void           checkScrollSize (FToggleButton*);
    void           checkScrollSize (const FRect&);

    // Event handlers
    void           onMouseDown (FMouseEvent*);
    void           onAccel (FAccelEvent*);
    void           onFocusIn (FFocusEvent*);

    // Callback method
    void           cb_buttonToggled (FWidget*, data_ptr);

  protected:
    // Accessor
    uChar          getHotkey();

    // Mutator
    void           setHotkeyAccelerator();

    // Methods
    virtual void   draw();
    void           drawLabel();

  private:
    // Disable copy constructor
    FButtonGroup (const FButtonGroup&);

    // Disable assignment operator (=)
    FButtonGroup& operator = (const FButtonGroup&);

    // Inquiries
    bool           isRadioButton (FToggleButton*) const;

    // Methods
    void           init();
    void           directFocus();

    // Data Members
    FString        text;
    FObjectList    buttonlist;
};
#pragma pack(pop)


// FButtonGroup inline functions
//----------------------------------------------------------------------
inline const char* FButtonGroup::getClassName() const
{ return "FButtonGroup"; }

//----------------------------------------------------------------------
inline bool FButtonGroup::setEnable()
{ return setEnable(true); }

//----------------------------------------------------------------------
inline bool FButtonGroup::unsetEnable()
{ return setEnable(false); }

//----------------------------------------------------------------------
inline bool FButtonGroup::setDisable()
{ return setEnable(false); }

//----------------------------------------------------------------------
inline uInt FButtonGroup::getCount() const
{ return uInt(buttonlist.size()); }

//----------------------------------------------------------------------
inline FString& FButtonGroup::getText()
{ return text; }

#endif  // FBUTTONGROUP_H