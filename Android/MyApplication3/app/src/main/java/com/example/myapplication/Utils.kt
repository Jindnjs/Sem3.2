package com.example.myapplication

import android.app.AlertDialog
import android.content.Context
import android.content.pm.PackageManager
import android.net.Uri
import androidx.core.content.ContextCompat
import android.content.Intent
import android.provider.Settings.ACTION_APPLICATION_DETAILS_SETTINGS


fun Context.isPermissionGranted(permission:String): Boolean{
    return ContextCompat.checkSelfPermission(this, permission) == PackageManager.PERMISSION_GRANTED
}

inline fun Context.cameraPermissionRequest(crossinline positive: () -> Unit){
    AlertDialog.Builder(this)
        .setTitle("Camera Permission Required")
        .setMessage("Without accessing the camera it is not possile to SCAN QR Codes...")
        .setPositiveButton("Allow Camera"){dialog, which ->
            positive.invoke()
        }.setNegativeButton("Cancle"){dialog, which ->

        }.show()
}

fun Context.openPermissionSetting(){
    Intent(ACTION_APPLICATION_DETAILS_SETTINGS).also{
        var uri: Uri = Uri.fromParts("package", packageName, null)
        it.data = uri
        startActivity(it)
    }
}
