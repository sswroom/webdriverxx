#ifndef WEBDRIVERXX_BROWSERS_CHROME_H
#define WEBDRIVERXX_BROWSERS_CHROME_H

#include "../capabilities.h"
#include <unordered_set>

namespace webdriverxx {
	namespace chrome {
		namespace device {
			std::unordered_set<std::string> deviceList{
				"BlackBerry Z30",
				"Blackberry PlayBook",
				"Galaxy Note 3",
				"Galaxy Note II",
				"Galaxy S III",
				"Galaxy S8",
				"Galaxy S9+",
				"Galaxy Tab S4",
				"Kindle Fire HDX",
				"LG Optimus L70",
				"Laptop with HiDPI screen",
				"Laptop with MDPI screen",
				"Laptop with touch",
				"Microsoft Lumia 550",
				"Microsoft Lumia 950",
				"Moto G Power",
				"Moto G4",
				"Nexus 10",
				"Nexus 4",
				"Nexus 5",
				"Nexus 5X",
				"Nexus 6",
				"Nexus 6P",
				"Nexus 7",
				"Nokia Lumia 520",
				"Nokia N9",
				"Pixel 3",
				"Pixel 4",
				"JioPhone 2",
				"iPhone SE",
				"iPhone XR",
				"iPhone 12 Pro",
				"iPhone 14 Pro Max",
				"Pixel 3 XL",
				"Pixel 7",
				"Samsung Galaxy S8+",
				"Samsung Galaxy S20 Ultra",
				"iPad Mini",
				"iPad Air",
				"iPad Pro",
				"Surface Pro 7",
				"Surface Duo",
				"Galaxy Z Fold 5",
				"Asus Zenbook Fold",
				"Samsung Galaxy A51/71",
				"Nest Hub",
				"Nest Hub Max",
				"Galaxy S5",
				"Pixel 2",
				"Pixel 2 XL",
				"iPhone 4",
				"iPhone 5/SE",
				"iPhone 6/7/8",
				"iPhone 6/7/8 Plus",
				"iPhone X",
				"iPad",
				"iPad Pro",
				"Galaxy Fold",
				"Facebook on Android"
			};

			std::string Get(const std::string& name) {
				auto pos = deviceList.find(name);
				if (pos != deviceList.end())
					return *pos;
				else
					return std::string();
			}

			struct deviceMetrics : JsonObject {
				WEBDRIVERXX_PROPERTIES_BEGIN(deviceMetrics)
					WEBDRIVERXX_PROPERTY(Width, "width", int)
					WEBDRIVERXX_PROPERTY(Height, "height", int)
					WEBDRIVERXX_PROPERTY(PixelRatio, "pixelRatio", float)
					WEBDRIVERXX_PROPERTY(Touch, "touch", bool)
					WEBDRIVERXX_PROPERTIES_END()
			};
		}

		struct MobileEmulation : JsonObject {
			WEBDRIVERXX_PROPERTIES_BEGIN(MobileEmulation)
				WEBDRIVERXX_PROPERTY(DeviceName, "deviceName", std::string)
				WEBDRIVERXX_PROPERTY(UserAgent, "userAgent", std::string)
				WEBDRIVERXX_PROPERTY(DeviceMetrics, "deviceMetrics", device::deviceMetrics)
				WEBDRIVERXX_PROPERTIES_END()
		};

		struct PerfLoggingPrefs : JsonObject {
			WEBDRIVERXX_PROPERTIES_BEGIN(PerfLoggingPrefs)
				WEBDRIVERXX_PROPERTY(EnableNetwork, "enableNetwork", bool)
				WEBDRIVERXX_PROPERTY(EnablePage, "enablePage", bool)
				WEBDRIVERXX_PROPERTY(EnableTimeline, "enableTimeline", bool)
				WEBDRIVERXX_PROPERTY(TraceCategories, "traceCategories", std::string)
				WEBDRIVERXX_PROPERTY(BufferUsageReportingInterval, "bufferUsageReportingInterval", int)
				WEBDRIVERXX_PROPERTIES_END()
		};

	} // namespace chrome

	struct ChromeOptions : JsonObject {
		WEBDRIVERXX_PROPERTIES_BEGIN(ChromeOptions)
			WEBDRIVERXX_PROPERTY(Args, "args", std::vector<std::string>)
			WEBDRIVERXX_PROPERTY(Binary, "binary", std::string)
			// Each extension is a base64-encoded .crx file
			WEBDRIVERXX_PROPERTY(Extensions, "extensions", std::vector<std::string>)
			WEBDRIVERXX_PROPERTY(LocalState, "localState", JsonObject)
			WEBDRIVERXX_PROPERTY(Prefs, "prefs", JsonObject)
			WEBDRIVERXX_PROPERTY(Detach, "detach", bool)
			WEBDRIVERXX_PROPERTY(DebuggerAddress, "debuggerAddress", std::string)
			WEBDRIVERXX_PROPERTY(ExcludeSwitches, "excludeSwitches", std::vector<std::string>)
			WEBDRIVERXX_PROPERTY(MinidumpPath, "minidumpPath", std::string)
			WEBDRIVERXX_PROPERTY(MobileEmulation, "mobileEmulation", chrome::MobileEmulation)
			WEBDRIVERXX_PROPERTY(WindowTypes, "windowTypes", std::vector<std::string>)
			WEBDRIVERXX_PROPERTY(SpecCompliantProtocol, "w3c", bool)

			// Read-only capabilities
			WEBDRIVERXX_PROPERTY_RONLY(ChromeDriverVersion, "chrome.chromedriverVersion", std::string)
			WEBDRIVERXX_PROPERTY_RONLY(UserDataDir, "userDataDir", std::string)

			WEBDRIVERXX_PROPERTY(LoggingPrefs, "loggingPrefs", LoggingPrefs)
			WEBDRIVERXX_PROPERTIES_END()
	};

	struct Chrome : Capabilities { // copyable
		Chrome(const Capabilities& defaults = Capabilities())
			: Capabilities(defaults) {
			SetBrowserName(browser::Chrome);
			// SetVersion(defaults.GetVersion());   // 加上这句就可以，BrowserName不能为空
			SetPlatform(platform::Any);
			SetPageLoadStrategy(page_load_strategy::Normal);
			SetChromeOptions(ChromeOptions());
		}

		// See https://sites.google.com/a/chromium.org/chromedriver/capabilities for details
		WEBDRIVERXX_PROPERTIES_BEGIN(Chrome)
			WEBDRIVERXX_PROPERTY(ChromeOptions, "goog:chromeOptions", ChromeOptions)
			WEBDRIVERXX_PROPERTY(PerfLoggingPrefs, "goog:perfLoggingPrefs", chrome::PerfLoggingPrefs)
			WEBDRIVERXX_PROPERTIES_END()
	};

} // namespace webdriverxx

#endif
