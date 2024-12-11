package com.example.myapplication

import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.graphics.Rect
import android.graphics.RectF
import com.google.mlkit.vision.face.Face

class FaceBox(
    overlay: FaceBoxOverLay,
    private val face: Face?,
    private val imageRect: Rect?,
    private val isDetected: Boolean // 얼굴 인식 여부
) : FaceBoxOverLay.FaceBox(overlay) {

    private val paint = Paint().apply {
        color = if (isDetected) Color.GREEN else Color.RED // 초록색: 인식 성공, 빨간색: 인식 실패
        style = Paint.Style.STROKE
        strokeWidth = 10.0f
    }

    override fun draw(canvas: Canvas?) {
        val rect = if (face != null && imageRect != null) {
            // 얼굴이 인식된 경우 얼굴 영역에 박스 그리기
            getBoxRect(
                imageRectWidth = imageRect.width().toFloat(),
                imageRectHeight = imageRect.height().toFloat(),
                faceBoundingBox = face.boundingBox
            )
        } else {
            // 얼굴이 인식되지 않은 경우 화면 전체 테두리에 박스 그리기
            RectF(0f, 0f, overlay.width.toFloat(), overlay.height.toFloat())
        }

        canvas?.drawRect(rect, paint)
    }
}