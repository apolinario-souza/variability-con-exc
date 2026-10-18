# Elbow goniometer for timing and accuracy tasks


Open hardware and software of a potentiometer-based elbow goniometer used in motor control
and learning studies (fast elbow flexion/extension to a spatial target with a target movement
time). The forearm moves an acrylic arm attached to a potentiometer; an Arduino reads the
potentiometer and sends the readings over serial to a LabVIEW program that presents the
stimulus, records each trial and gives online feedback.

## Contents

| Path | Content |
|---|---|
| `hardware/Braço acrílico.dxf`, `.dwg` | Acrylic arm (laser cutting) |
| `hardware/Suporte potenciômetro.stl` | Potentiometer mount (3D printing) |
| `hardware/Suporte móvel.stl` | Movable support (3D printing) |
| `hardware/buckle.stl` | Buckle (3D printing) |
| `arduino/v1.ino` | Arduino code: reads the potentiometer (analog pin A0) every 5 ms and sends it over serial at 9600 baud |
| `labview/v6.vi` | LabVIEW source of the data collection program (LabVIEW 2025 Q3) |
| `labview/Ref_colunas.xls` | Column headers of the block summary files |
| `labview/Ref_colunas_tentativa_tentativa.xls` | Column headers of the trial trace files |
| `software/` | Compiled program (Windows) built from `v6.vi` |

## Parts list

[TODO: potentiometer model, Arduino board, acrylic thickness, screws/bearings, bench, cables.]

## Assembly

[TODO: assembly steps, how the arm is aligned with the elbow joint.]

## Software

- Upload `arduino/v1.ino` to the Arduino.
- Run `software/Application.exe` (Windows). It requires the
  [LabVIEW Run-Time Engine](https://www.ni.com/en/support/downloads/software-products/download.labview-runtime.html)
  2025 Q3 (or compatible) and NI-VISA (serial communication). Alternatively, open `labview/v6.vi`
  in LabVIEW 2025 Q3 or later.

[TODO: describe the program: how the target, load and action are set, stimulus timing,
feedback given, and the files it saves.]

### Output files

- `<condition>_tentativa_N.xls`: trace of each trial (tab-separated text, no header, comma as
  decimal separator). Columns: frame, position (raw units), velocity (raw units), angle (°),
  angular velocity (°/s). Each frame is 5 ms; the stimulus occurs at frame 800.
- `<condition>.txt`: one line per trial with reaction time (ms), movement time (ms), absolute
  error (°), constant error (°) and peak velocity (°/s). Movement onset and end are defined at
  20% of peak velocity.

## Calibration

[TODO: how raw potentiometer units are converted into degrees, and how velocity is computed.]

> **TODO:** in the data collected with `v6.vi`, the derivative of the angle column (5 ms per
> frame) peaks at about twice the angular velocity column. Check whether the angle or the
> velocity scale is off by a factor of 2 and document the correct conversion here. Also check
> the actual sampling rate: `delay(5)` plus serial transmission gives slightly less than 200 Hz.

## Versions and citation

Each study should cite the release used to collect its data. [TODO: create a release (e.g.
`v1.0`, LabVIEW program `v6.vi`) and archive it on Zenodo to get a DOI.]

Studies that used this equipment:

- [TODO: article on load and contraction type (data repository link)]

## License

Code (Arduino, LabVIEW): MIT. Hardware design files: CC BY 4.0. See `LICENSE`.
