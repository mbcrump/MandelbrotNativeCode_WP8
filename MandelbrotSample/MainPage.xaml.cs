using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using MandelbrotSample.Resources;
using MandelbrotAlgorithm;
using System.Windows.Media.Imaging;
using Windows.UI;

namespace MandelbrotSample
{
    public partial class MainPage : PhoneApplicationPage
    {
        // Constructor
        public MainPage()
        {
            InitializeComponent();

            // Sample code to localize the ApplicationBar
            //BuildLocalizedApplicationBar();
        }

        private void RenderButton_Click(object sender, RoutedEventArgs e)
        {
            // should be dynamic
            const int width = 600;
            const int height = 600;

            // this creates a windows runtime component,
            // and the original native implementation behind the scenes
            var mandelbrotRenderer = new MandelbrotAlgorithmRuntimeComponent();

            // define the parameters and invoke the native code
            var result = new double[width * height];
            double maxResult;
            mandelbrotRenderer.Render(width, height, result, out maxResult);

            // create the visual representation as bitmap
            var bitmap = new WriteableBitmap(width, height);
            for (int i = 0; i < result.Length; i++)
            {
                // do a bit of normalization so we get more fancy colors
                var normalizedColor = (byte)((result[i] / maxResult) * 255);
                
                // convert to something that's blue in ARGB
                bitmap.Pixels[i] = 255 << 24 | 0 << 16 | 0 << 8 | normalizedColor;
            }

            // set the source of the image control to the created bitmap
            Image.Source = bitmap;
        }

        // Sample code for building a localized ApplicationBar
        //private void BuildLocalizedApplicationBar()
        //{
        //    // Set the page's ApplicationBar to a new instance of ApplicationBar.
        //    ApplicationBar = new ApplicationBar();

        //    // Create a new button and set the text value to the localized string from AppResources.
        //    ApplicationBarIconButton appBarButton = new ApplicationBarIconButton(new Uri("/Assets/AppBar/appbar.add.rest.png", UriKind.Relative));
        //    appBarButton.Text = AppResources.AppBarButtonText;
        //    ApplicationBar.Buttons.Add(appBarButton);

        //    // Create a new menu item with the localized string from AppResources.
        //    ApplicationBarMenuItem appBarMenuItem = new ApplicationBarMenuItem(AppResources.AppBarMenuItemText);
        //    ApplicationBar.MenuItems.Add(appBarMenuItem);
        //}
    }
}