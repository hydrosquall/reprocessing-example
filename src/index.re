open Reprocessing;

type stateT = {
  angle: float
};

let setup = (env) : stateT => {
  Env.size(~width=400, ~height=400, env);
  {
    angle: 0.
  };
}

let draw = (_state: stateT, env): stateT => {

  let { angle } = _state;

  Draw.background(Utils.color(~r=0, ~g=0, ~b=0, ~a=255), env);
  Draw.fill(Utils.color(~r=255,~g=255,~b=255, ~a=255), env);

  let value = int_of_float(sin(angle) *. 100.);
  let height = Utils.remap(~value, ~low1=-100, ~high1=100, ~low2=0, ~high2=200);

  Draw.rect(~pos=(150, 150),
            ~width=150,
            ~height=height, env);

  {
    angle: (angle +. 0.1)
  };
};

run(~setup, ~draw, ());
