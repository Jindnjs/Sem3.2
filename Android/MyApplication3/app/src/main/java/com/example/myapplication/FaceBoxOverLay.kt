package com.example.myapplication

import android.content.Context
import android.util.AttributeSet
import android.view.View
import android.graphics.Canvas
import android.graphics.Rect
import android.graphics.RectF
import kotlin.math.ceil

class FaceBoxOverLay(context: Context, attrs: AttributeSet?) : View(context, attrs){

    private val lock = Any()
    private val faceBoxes: MutableList<FaceBox> = mutableListOf();
    var mScale: Float = 1.0f
    var mOffsetX: Float = 0.0f
    var mOffsetY: Float = 0.0f

    abstract class FaceBox(protected val overlay: FaceBoxOverLay){
        abstract fun draw(canvas: Canvas?)

        fun getBoxRect(imageRectWidth: Float, imageRectHeight: Float, faceBoundingBox: Rect): RectF {
            val scaleX = overlay.width.toFloat()
            val scaleY = overlay.height.toFloat()
            val scale = scaleX.coerceAtMost(scaleY)

            val offsetX = (overlay.width.toFloat() - imageRectWidth * scale) / 2.0f
            val offsetY = (overlay.height.toFloat() - imageRectHeight * scale) / 2.0f

            return RectF(
                faceBoundingBox.left * scale + offsetX,
                faceBoundingBox.top * scale + offsetY,
                faceBoundingBox.right * scale + offsetX,
                faceBoundingBox.bottom * scale + offsetY
            )


        }
    }
    fun clear() {
        synchronized(lock) { faceBoxes.clear()}
        postInvalidate()
    }
    fun add(faceBox:FaceBox){
        synchronized(lock) { faceBoxes.add(faceBox) }
        postInvalidate()
    }

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)
        synchronized(lock){
            for (graphic in faceBoxes){
                graphic.draw(canvas)
            }
        }
    }
}
