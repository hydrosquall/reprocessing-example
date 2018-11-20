open Reprocessing;

type stateT = {
  angle: float,
}

let setup = (env) => {
  Env.size(~width=600,
            ~height=600,
            env);

  {
    angle: 0.,
  }
}

let backgroundColor = Utils.color(~r=0, ~g=0, ~b=0, ~a=255);
let foregroundColor = Utils.color(~r=255, ~g=255, ~b=255, ~a=255);

/* Curry this */
let angleScale = Utils.remapf(~low1=-1.,
                              ~high1=1.,
                              ~low2=10.,
                              ~high2=200.)

let draw = (_state, env) => {
  /* Drawing Setup */
  Draw.background(backgroundColor, env);
  Draw.fill(foregroundColor, env);
  Draw.rectMode(Center, env);

  /* Draw from center of page */
  let midpointX = float_of_int(env.size.width) /. 2.;
  let midpointY = float_of_int(env.size.height) /. 2.;

  Draw.translate(~x=midpointX,
                 ~y=midpointY,
                 env);
  let { angle } = _state;

  let oscillator = sin(angle);
  let height = int_of_float(Utils.remapf(~value=oscillator,
                                          ~low1=-1.,
                                          ~high1=1.,
                                          ~low2=10.,
                                          ~high2=200.));

  /* Make row of rectangles */
  let barWidth = 30;
  let barPadding = 4;
  let numBars = (env.size.width / (barWidth + barPadding)) + 3; /* magic extra 3*/
  let xOffset = env.size.width / 2 + barWidth / 2;
  let drawWidth = barWidth - barPadding;

  let angleOffset = 0.1; /*. controls ripple - 1.1 is interesting */
  let offset = 0.;

  for (i in 0 to numBars) {
    let pos = (
      barWidth * i - xOffset,
      0
    );

    let a = angle +. (offset +. angleOffset *. float_of_int(i));
    let h = int_of_float(angleScale(~value=sin(a)));

    Draw.rect(~pos,
            ~width=drawWidth,
            ~height=h,
            env);

  };

  { angle: angle +. 0.1}
};

run(~setup, ~draw, ());
