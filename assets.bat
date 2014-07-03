:: script to copy new assets into the build folders
@echo on

:: remove old assets
rmdir /s /q "platformer/Debug/assets"
rmdir /s /q "platformer/Release/assets"

:: copy new assets
xcopy "assets" "platformer/Debug" /s /e /v
xcopy "assets" "platformer/Release" /s /e /v
xcopy "assets" "platformer" /s /e /v