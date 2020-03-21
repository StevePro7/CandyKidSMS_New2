::@echo off

:: Time build START
:: Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


:: Compile
cd devkit
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _snd_manager.c
cd ..


cd engine
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 asm_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 actor_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 audio_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 board_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 collision_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 command_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 content_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 font_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 function_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 input_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 locale_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 memo_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 move_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 score_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 screen_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 sprite_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 state_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 storage_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tile_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 timer_manager.c
cd ..

cd object
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 score_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 storage_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 timer_object.c
cd ..

cd screen
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 none_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 splash_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 intro_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 title_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 demo_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 select_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 option_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 init_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 load_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 ready_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 play_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 pass_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 bonus_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 replay_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 reset_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 dead_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 cont_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 over_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 beat_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 boss_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 record_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 save_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 test_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 func_screen.c
cd ..


:: echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


:: Time build -END-
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


:: Link
sdcc -o output.ihx -mz80 --no-std-crt0 --data-loc 0xC000 ^
..\crt0\crt0_sms.rel main.rel ^
-Wl-b_BANK2=0x8000  -Wl-b_BANK3=0x8000  -Wl-b_BANK4=0x8000  -Wl-b_BANK5=0x8000 ^
-Wl-b_BANK6=0x8000  -Wl-b_BANK7=0x8000  -Wl-b_BANK8=0x8000  -Wl-b_BANK9=0x8000 ^
-Wl-b_BANK10=0x8000 -Wl-b_BANK11=0x8000 -Wl-b_BANK12=0x8000 -Wl-b_BANK13=0x8000 ^
-Wl-b_BANK14=0x8000 -Wl-b_BANK15=0x8000 ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel  banks\bank3.rel  banks\bank4.rel  banks\bank5.rel ^
banks\bank6.rel  banks\bank7.rel  banks\bank8.rel  banks\bank9.rel ^
banks\bank10.rel banks\bank11.rel banks\bank12.rel banks\bank13.rel ^
banks\bank14.rel banks\bank15.rel ^
devkit\_sms_manager.rel devkit\_snd_manager.rel ^
gfx.rel

:: Execute
ihx2sms output.ihx output.sms


:: Delete
cd banks
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd devkit
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..
cd engine
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..
cd object
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd screen
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

if exist "*.asm" del "*.asm" > nul; if exist "*.ihx" del "*.ihx" > nul; if exist "*.lk"  del "*.lk"  > nul
if exist "*.lst" del "*.lst" > nul; if exist "*.noi" del "*.noi" > nul; if exist "*.sym" del "*.sym" > nul


:: Run
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms
::C:\SEGA\meka\mekaw.exe output.sms
::output.sms