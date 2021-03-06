/**
 * \file draw3dCameraParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "draw3dCameraParametersControlWidget.h"
#include "ui_draw3dCameraParametersControlWidget.h"
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"

#include "rgbColorParametersControlWidget.h"
#include "rgbColorParametersControlWidget.h"
#include "rgbColorParametersControlWidget.h"
#include "rgbColorParametersControlWidget.h"

Draw3dCameraParametersControlWidget::Draw3dCameraParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::Draw3dCameraParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->fovHSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->fovVSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->nearPlaneSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->farPlaneSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->styleComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->pointColorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->pointColorOverrideCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->pointSizeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->edgeColorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->edgeColorOverrideCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->edgeWidthSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->faceColorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->faceColorOverrideCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->showCaptionCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->fontSizeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->fontWidthSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->fontColorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureCorrodinatesComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureScaleSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalMatrixTypeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalLeftCamCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalLeftAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalRightCamCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalRightAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
}

Draw3dCameraParametersControlWidget::~Draw3dCameraParametersControlWidget()
{

    delete mUi;
}

void Draw3dCameraParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    Draw3dCameraParameters *params = createParameters();
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
    delete params;
}

void Draw3dCameraParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    Draw3dCameraParameters *params = createParameters();
    saver.saveParameters(*params, rootPath);
    delete params;
}

 /* Composite fields are NOT supported so far */
void Draw3dCameraParametersControlWidget::getParameters(Draw3dCameraParameters& params) const
{

    params.setFovH             (mUi->fovHSpinBox->value());
    params.setFovV             (mUi->fovVSpinBox->value());
    params.setNearPlane        (mUi->nearPlaneSpinBox->value());
    params.setFarPlane         (mUi->farPlaneSpinBox->value());
    params.setStyle            (static_cast<Draw3dStyle::Draw3dStyle>(mUi->styleComboBox->currentIndex()));
//    params.setPointColor       (mUi->pointColorControlWidget->createParameters());
    params.setPointColorOverride(mUi->pointColorOverrideCheckBox->isChecked());
    params.setPointSize        (mUi->pointSizeSpinBox->value());
//    params.setEdgeColor        (mUi->edgeColorControlWidget->createParameters());
    params.setEdgeColorOverride(mUi->edgeColorOverrideCheckBox->isChecked());
    params.setEdgeWidth        (mUi->edgeWidthSpinBox->value());
//    params.setFaceColor        (mUi->faceColorControlWidget->createParameters());
    params.setFaceColorOverride(mUi->faceColorOverrideCheckBox->isChecked());
    params.setShowCaption      (mUi->showCaptionCheckBox->isChecked());
    params.setFontSize         (mUi->fontSizeSpinBox->value());
    params.setFontWidth        (mUi->fontWidthSpinBox->value());
//    params.setFontColor        (mUi->fontColorControlWidget->createParameters());
    params.setTextureCorrodinates(static_cast<Draw3dTextureGen::Draw3dTextureGen>(mUi->textureCorrodinatesComboBox->currentIndex()));
    params.setTextureAlpha     (mUi->textureAlphaSpinBox->value());
    params.setTextureScale     (mUi->textureScaleSpinBox->value());
    params.setDecalMatrixType  (mUi->decalMatrixTypeSpinBox->value());
    params.setDecalLeftCam     (mUi->decalLeftCamCheckBox->isChecked());
    params.setDecalLeftAlpha   (mUi->decalLeftAlphaSpinBox->value());
    params.setDecalRightCam    (mUi->decalRightCamCheckBox->isChecked());
    params.setDecalRightAlpha  (mUi->decalRightAlphaSpinBox->value());

}

Draw3dCameraParameters *Draw3dCameraParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/

    RgbColorParameters *tmp5 = NULL;
    RgbColorParameters *tmp8 = NULL;
    RgbColorParameters *tmp11 = NULL;
    RgbColorParameters *tmp16 = NULL;

    Draw3dCameraParameters *result = new Draw3dCameraParameters(
          mUi->fovHSpinBox->value()
        , mUi->fovVSpinBox->value()
        , mUi->nearPlaneSpinBox->value()
        , mUi->farPlaneSpinBox->value()
        , static_cast<Draw3dStyle::Draw3dStyle>(mUi->styleComboBox->currentIndex())
        , * (tmp5 = mUi->pointColorControlWidget->createParameters())
        , mUi->pointColorOverrideCheckBox->isChecked()
        , mUi->pointSizeSpinBox->value()
        , * (tmp8 = mUi->edgeColorControlWidget->createParameters())
        , mUi->edgeColorOverrideCheckBox->isChecked()
        , mUi->edgeWidthSpinBox->value()
        , * (tmp11 = mUi->faceColorControlWidget->createParameters())
        , mUi->faceColorOverrideCheckBox->isChecked()
        , mUi->showCaptionCheckBox->isChecked()
        , mUi->fontSizeSpinBox->value()
        , mUi->fontWidthSpinBox->value()
        , * (tmp16 = mUi->fontColorControlWidget->createParameters())
        , static_cast<Draw3dTextureGen::Draw3dTextureGen>(mUi->textureCorrodinatesComboBox->currentIndex())
        , mUi->textureAlphaSpinBox->value()
        , mUi->textureScaleSpinBox->value()
        , mUi->decalMatrixTypeSpinBox->value()
        , mUi->decalLeftCamCheckBox->isChecked()
        , mUi->decalLeftAlphaSpinBox->value()
        , mUi->decalRightCamCheckBox->isChecked()
        , mUi->decalRightAlphaSpinBox->value()
    );
    delete tmp5;
    delete tmp8;
    delete tmp11;
    delete tmp16;
    return result;
}

void Draw3dCameraParametersControlWidget::setParameters(const Draw3dCameraParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->fovHSpinBox->setValue(input.fovH());
    mUi->fovVSpinBox->setValue(input.fovV());
    mUi->nearPlaneSpinBox->setValue(input.nearPlane());
    mUi->farPlaneSpinBox->setValue(input.farPlane());
    mUi->styleComboBox->setCurrentIndex(input.style());
    mUi->pointColorControlWidget->setParameters(input.pointColor());
    mUi->pointColorOverrideCheckBox->setChecked(input.pointColorOverride());
    mUi->pointSizeSpinBox->setValue(input.pointSize());
    mUi->edgeColorControlWidget->setParameters(input.edgeColor());
    mUi->edgeColorOverrideCheckBox->setChecked(input.edgeColorOverride());
    mUi->edgeWidthSpinBox->setValue(input.edgeWidth());
    mUi->faceColorControlWidget->setParameters(input.faceColor());
    mUi->faceColorOverrideCheckBox->setChecked(input.faceColorOverride());
    mUi->showCaptionCheckBox->setChecked(input.showCaption());
    mUi->fontSizeSpinBox->setValue(input.fontSize());
    mUi->fontWidthSpinBox->setValue(input.fontWidth());
    mUi->fontColorControlWidget->setParameters(input.fontColor());
    mUi->textureCorrodinatesComboBox->setCurrentIndex(input.textureCorrodinates());
    mUi->textureAlphaSpinBox->setValue(input.textureAlpha());
    mUi->textureScaleSpinBox->setValue(input.textureScale());
    mUi->decalMatrixTypeSpinBox->setValue(input.decalMatrixType());
    mUi->decalLeftCamCheckBox->setChecked(input.decalLeftCam());
    mUi->decalLeftAlphaSpinBox->setValue(input.decalLeftAlpha());
    mUi->decalRightCamCheckBox->setChecked(input.decalRightCam());
    mUi->decalRightAlphaSpinBox->setValue(input.decalRightAlpha());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void Draw3dCameraParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    Draw3dCameraParameters *inputCasted = static_cast<Draw3dCameraParameters *>(input);
    setParameters(*inputCasted);
}
