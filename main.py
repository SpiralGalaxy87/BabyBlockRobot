import sys
import time
import subprocess, os
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler


class MyHandler(FileSystemEventHandler):
    # Cache to check for duplicates
    file_cache = {}

    def checkForCPP(self, event):
        # Check if extension is cpp
        ext = "".join(reversed(event.src_path))
        return ext[0:3] == "ppc"

    def on_modified(self, event):
        # Check if is not dir and is a cpp file
        if not event.is_directory and self.checkForCPP(event):
            # Check for duplicate
            seconds = int(time.time() / 10)
            key = (seconds, event.src_path)
            if key in self.file_cache:
                return
            self.file_cache[key] = True

            # State what was modified
            print(event.src_path + " was " + event.event_type)

            # Print the contents of the file - for debugging only
            # subprocess.run(["cat", event.src_path])

            # Compile and run the code
            # subprocess.run("clear")
            compProcess = subprocess.run(
                ["g++", "-o", "CompiledCode", event.src_path, "robot_functions.cpp"],
                shell=True,
            )
            time.sleep(0.1)
            # Check if compilation was successful
            if compProcess.returncode == 0:
                print("\n\nYour program is below!\nRe-save file to restart.\n\n")
                # subprocess.run("./CompiledCode", shell=True)
                subprocess.run(["start", "CompiledCode"], shell=True)
                print("\n\nDone\n")
            else:
                print(
                    "\n\nYour code did not compile, returned with code 1\nRe-save file to restart.\n\n"
                )


if __name__ == "__main__":
    event_handler = MyHandler()
    observer = Observer()
    observer.schedule(event_handler, "./", recursive=True)
    observer.start()
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
