/*
 Copyright 2010, 2011 Tarik Sekmen.

 All Rights Reserved.

 Written by Tarik Sekmen <tarik@ilixi.org>.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "WidgetGallery.h"
#include "ilixiGUI.h"
#include "ui/VBoxLayout.h"
#include "ui/HBoxLayout.h"
#include "ui/GridLayout.h"
#include "core/Logger.h"

#include "types/Video.h"

using namespace ilixi;

WidgetGallery::WidgetGallery(int argc, char* argv[]) :
  Application(argc, argv)
{
  setTitle("Widget Gallery");
  setLayout(new VBoxLayout());

  TabPanel* tabs = new TabPanel();
  addWidget(tabs);

  // Create ToolButtons
  GridLayout* toolButtonLayout = new GridLayout(2, 3);
  tabs->addPage(toolButtonLayout, "ToolButton");

  ToolButton* toolButton1 = new ToolButton("IconAboveText");
  toolButton1->setCheckable(true);
  toolButton1->setChecked(true);
  toolButton1->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  toolButton1->setToolButtonStyle(ToolButton::IconAboveText);
  toolButtonLayout->addWidget(toolButton1);

  ToolButton* toolButton2 = new ToolButton("IconBelowText");
  toolButton2->setCheckable(true);
  toolButton2->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  toolButton2->setToolButtonStyle(ToolButton::IconBelowText);
  toolButtonLayout->addWidget(toolButton2);

  ToolButton* toolButton3 = new ToolButton("IconBeforeText");
  toolButton3->setCheckable(true);
  toolButton3->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  toolButton3->setToolButtonStyle(ToolButton::IconBeforeText);
  toolButtonLayout->addWidget(toolButton3);

  ToolButton* toolButton4 = new ToolButton("Not checkable");
  //  toolButton4->setCheckable(true);
  toolButton4->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  //  toolButton4->setToolButtonStyle(ToolButton::IconOnly);
  toolButtonLayout->addWidget(toolButton4);

  ToolButton* toolButton5 = new ToolButton("No Image");
  toolButton5->setCheckable(true);
  toolButtonLayout->addWidget(toolButton5);

  ToolButton* toolButton6 = new ToolButton("Disabled");
  toolButton6->setCheckable(true);
  toolButton6->setDisabled();
  toolButton6->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  toolButton6->setToolButtonStyle(ToolButton::IconBeforeText);
  toolButtonLayout->addWidget(toolButton6);

  // Create PushButtons
  GridLayout* pushButtonLayout = new GridLayout(2, 2);
  tabs->addPage(pushButtonLayout, "PushButton");

  PushButton* pushButton1 = new PushButton("Fixed H. Constraint");
  pushButton1->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  pushButton1->setHConstraint(FixedConstraint);
  pushButtonLayout->addWidget(pushButton1);

  PushButton* pushButton2 = new PushButton("Checkable");
  pushButton2->setCheckable(true);
  pushButton2->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  pushButtonLayout->addWidget(pushButton2);

  PushButton* pushButton3 = new PushButton("Disabled");
  pushButton3->setDisabled();
  pushButton3->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  pushButtonLayout->addWidget(pushButton3);

  PushButton* pushButton4 = new PushButton("No Image");
  pushButton4->setCheckable(true);
  pushButtonLayout->addWidget(pushButton4);

  // Create Radio and Checkbox
  GridLayout* otherButtonLayout = new GridLayout(2, 3);
  tabs->addPage(otherButtonLayout, "Radio");

  RadioButton* radio1 = new RadioButton("Radio");
  otherButtonLayout->addWidget(radio1);

  RadioButton* radio2 = new RadioButton("Radio with image");
  radio2->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  otherButtonLayout->addWidget(radio2);

  RadioButton* radio3 = new RadioButton("Disabled");
  radio3->setDisabled();
  otherButtonLayout->addWidget(radio3);

  Checkbox* checkbox1 = new Checkbox("Tri-state checkbox");
  checkbox1->setTriState(true);
  otherButtonLayout->addWidget(checkbox1);

  Checkbox* checkbox2 = new Checkbox("Checkbox with image");
  checkbox2->setIcon(ILIXI_DATADIR"colors.png", Size(48, 48));
  otherButtonLayout->addWidget(checkbox2);

  Checkbox* checkbox3 = new Checkbox("Disabled");
  checkbox3->setDisabled();
  otherButtonLayout->addWidget(checkbox3);

  // Sliders
  GridLayout* sliderLayout = new GridLayout(3, 3);
  tabs->addPage(sliderLayout, "Slider");

  Slider* sliderh1 = new Slider();
  sliderh1->setHConstraint(NoConstraint);
  sliderh1->setMaximumSize(100, 100);
  sliderh1->setValue(20);
  sliderLayout->addWidget(sliderh1, 0, 0, 1, 2);

  Slider* sliderh2 = new Slider();
  sliderh2->setHConstraint(NoConstraint);
  sliderh2->setMaximumSize(100, 100);
  sliderh2->setInverted(true);
  sliderh2->setValue(20);
  sliderLayout->addWidget(sliderh2, 1, 0, 1, 2);

  Slider* sliderv1 = new Slider();
  sliderv1->setOrientation(Vertical);
  sliderv1->setValue(20);
  sliderLayout->addWidget(sliderv1, 2, 0, 1, 1);

  Slider* sliderv2 = new Slider();
  sliderv2->setOrientation(Vertical);
  sliderv2->setInverted(true);
  sliderv2->setValue(20);
  sliderLayout->addWidget(sliderv2, 2, 1, 1, 1);

  ScrollArea* scrollArea = new ScrollArea();
  scrollArea->setLayout(new VBoxLayout());
  scrollArea->setBorderStyle(StyledBorder);
  scrollArea->addWidget(new PushButton("Test 1"));
  scrollArea->addWidget(new RadioButton("Test 2"));
  scrollArea->addWidget(new PushButton("Test 3"));
  scrollArea->addWidget(new RadioButton("Test 4"));
  scrollArea->addWidget(new PushButton("Test 5"));
  scrollArea->addWidget(new RadioButton("Test 6"));
  scrollArea->addWidget(new PushButton("Test 7"));
  scrollArea->addWidget(new PushButton("Test 8"));
  sliderLayout->addWidget(scrollArea, 0, 2, -1, -1);

  // Line edit
  GridLayout* inputLayout = new GridLayout(3, 2);
  tabs->addPage(inputLayout, "Other Inputs");

  inputLayout->addWidget(new Label("SpinBox"));
  SpinBox* spin = new SpinBox();
  inputLayout->addWidget(spin);

  inputLayout->addWidget(new Label("LineEdit"));
  LineEdit* input = new LineEdit("enter text here...");
  inputLayout->addWidget(input);

  inputLayout->addWidget(new Label("ComboBox"));
  ComboBox* cbox = new ComboBox("Select an option");
  inputLayout->addWidget(cbox);
  cbox->addItem("Option 1");
  cbox->addItem("Option 2");
  cbox->addItem("Option 3");
  cbox->addItem("Option 4");
  cbox->addItem("Option 5");
  cbox->addItem("Option 6");
  cbox->addItem("Option 7");
  cbox->addItem("Option 8");
  cbox->addItem("Option 9");

  // Actions
  VBoxLayout* actionLayout = new VBoxLayout();
  tabs->addPage(actionLayout, "Actions");

  Slider* slider4 = new Slider();
  actionLayout->addWidget(slider4);

  ProgressBar* bar = new ProgressBar();
  actionLayout->addWidget(bar);

  slider4->sigValueChanged.connect(sigc::mem_fun(bar, &ProgressBar::setValue));

  actionLayout->addWidget(
      new Label(
          "In this example slider's value changed signal is connected to progress bar's set value method."));
}

WidgetGallery::~WidgetGallery()
{
  //  delete dia;
}

int
main(int argc, char* argv[])
{
  WidgetGallery app(argc, argv);
  app.exec();
  return 0;
}
