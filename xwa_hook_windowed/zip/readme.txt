xwa_hook_windowed

This hook enables windowed mode.


*** Requirements ***

This dll requires:
- Windows 7 or superior
- xwa_hook_main


*** Setup ***

Place hook_windowed.dll and hook_windowed.cfg next to xwingalliance.exe


*** Patch ***

The following modifications are applied at runtime to xwingalliance.exe:

# To call the hook that enables windowed mode
At offset 10AA8C, replace E88FFEF1FF with E89FD40900.
At offset 10AB00, replace E83B00F2FF with E82BD40900.
At offset 057CD5, replace E8A62DFDFF with E856021500.
At offset 10BB4A, replace E831EFF1FF with E8E1C30900.
At offset 10BE78, replace E803ECF1FF with E8B3C00900.
At offset 10BE9A, replace E8E1EBF1FF with E891C00900.
At offset 10C1C8, replace E8B3E8F1FF with E863BD0900.
At offset 0F8E5A, replace E8A11EF3FF with E8D1F00A00.
At offset 057CDA, replace E84130FDFF with E841021500.
At offset 05CA29, replace E8F2E2FCFF with E8F2B41400.
At offset 0F8F5F, replace E8BC1DF3FF with E8BCEF0A00.
At offset 13DF71, replace 6A0489442428FF1544905A00 with 89442424E8B69F0600909090.
At offset 13DF98, replace 53568B3544925A0053536A01FFD65053FFD6505353680000009068C030600068C030600053FF1540925A00 with 5650E8919F060083C408909090909090909090909090909090909090909090909090909090909090909090.
At offset 13D951, replace 5150FF1574925A00 with 9090E8D8A5060090.
At offset 15AE9F, replace 5150A3ED659F00890DF1659F00FF1574925A00 with 9090A3ED659F00890DF1659F00E87FD0040090.
At offset 15AEB9, replace 5150A3ED659F00890DF1659F00FF1574925A00 with 9090A3ED659F00890DF1659F00E865D0040090.
At offset 13E079, replace 5353FF1574925A00 with 9090E8B09E060090.
At offset 13F49E, replace 6A006A00FF1574925A00 with 90909090E8898A060090.
At offset 13FB6E, replace 6A006A00A30B7F9F00FF1574925A00 with 90909090A30B7F9F00E8B483060090.

# To call the hook that shows a splash screen
At offset 13E9D0, replace A12A709F0083EC74 with E84B950600C39090.

# To call the hook that paused the game
At offset 0F8CBB, replace E8C01D0100 with E870F20A00.
At offset 0F8C57, replace 753D with EB47.
At offset 0F8CA5, replace E8E6FDF8FF with 9090909090.


*** Usage ***

To set the window position and size, modify the "hook_windowed.cfg" file or the "hook_windowed" section of "hooks.ini":
X = left value
Y = top value
Width = width value
Height = height value
The minimum value for "Width" is 640.
The minimum value for "Height" is 480.

When "Width" or "Height" is 0, default values are used: the window will be fullscreen.

To set a splash screen, create an image named "Splash.jpg". If this image doesn't exist then "Alliance.jpg" is used. If this image doesn't exist then a white screen is rendered.
You can enable or disable the splash screen with the ShowSplashScreen setting. 0 means no and 1 means yes.


*** Credits ***

- Jérémy Ansel (JeremyaFr)
