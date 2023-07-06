package com.wc.hellocppvendorlibrary

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.wc.hellocppvendorlibrary.ui.theme.HelloCppVendorLibraryTheme

class MainActivity : ComponentActivity() {

    companion object {
        init {
            System.loadLibrary("helloNativeLib");
            System.loadLibrary("helloSharedLib");
        }
    }
    // Note: declare functions from C++ libraries
    external fun stringFromHelloSharedLib(): String
    external fun stringFromHelloStaticLib(): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            HelloCppVendorLibraryTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    var text1 = stringFromHelloSharedLib()
                    var text2 = stringFromHelloStaticLib()

                    Column(Modifier.padding(16.dp)) {
                        Greeting(text1)
                        Greeting(text2)
                    }
                }
            }
        }
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "$name",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    HelloCppVendorLibraryTheme {
        Greeting("Android")
    }
}