import React, { useState, useEffect } from "react";
import { SketchPicker } from "react-color";
import fontColorContrast from "font-color-contrast";
import { useOpen } from "react-modal-pirate"

import "./App.css";

function rowStrategy(m, n) {
  const computed = [];
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      const cellNumber = i * n + j;
      computed.push(cellNumber);
    }
  }
  return computed;
}

function columnStrategy(m, n) {
  const computed = [];
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      const cellNumber = j * m + i;
      computed.push(cellNumber);
    }
  }
  return computed;
}

const countStrategiesList = {
  column: columnStrategy,
  row: rowStrategy,
  columnSnake: (m, n) => {},
  rowSnake: (m, n) => {}
};

function App() {
  const [m, setM] = useState(0);
  const [n, setN] = useState(0);
  const [countStrategy, setCountStrategy] = useState("column");
  const [colors, setColors] = useState([]);
  const [realIndexToPosition, setRealIndexToPosition] = useState([]);
  const [c, setC] = useState("#000000");
  const [currentPixel, setCurrentPixel] = useState(null);
  const [colorOrder, setColorOrder] = useState("r g b");

  const openModal = useOpen()

  useEffect(() => {
    let computed = [];

    if (countStrategy === "manual") {
      for (let i = 0; i < m * n; i++) computed.push(NaN);
    } else {
      computed = countStrategiesList[countStrategy](m, n);
    }
    setRealIndexToPosition(computed);

  }, [countStrategy, m, n]);

  const maxLen = String(m * n).length;
  const matrix = [];
  for (let i = 0; i < m; i++) {
    const row = [];
    for (let j = 0; j < n; j++) {
      const cellNumber = i * n + j;
      let cellRealIndex = "";
      if (!isNaN(realIndexToPosition[cellNumber])) {
        cellRealIndex = String(realIndexToPosition[cellNumber]);
      }
      row.push(
        <div
          className="cell"
          onClick={() => {
            if (!isNaN(realIndexToPosition[cellNumber])) {
              if (currentPixel !== realIndexToPosition[cellNumber]) {
                setCurrentPixel(realIndexToPosition[cellNumber]);
                if (colors[realIndexToPosition[cellNumber]] !== undefined) {
                  setC(colors[realIndexToPosition[cellNumber]]);
                }
              } else {
                setCurrentPixel(null);
              }
            } else {
              setRealIndexToPosition(prev => {
                let max = -1;
                if (
                  Math.max(...realIndexToPosition.filter(i => !isNaN(i))) !==
                  -Infinity
                ) {
                  max = Math.max(...realIndexToPosition.filter(i => !isNaN(i)));
                }
                const next = [...prev];
                next[cellNumber] = max + 1;
                return next;
              });
            }
          }}
          style={{
            borderWidth:
              currentPixel === realIndexToPosition[cellNumber] ? "2px" : "1px",
            backgroundColor:
              colors[realIndexToPosition[cellNumber]]?.hex ?? "#000000",
            color: fontColorContrast(
              colors[realIndexToPosition[cellNumber]]?.hex ?? "#000000"
            )
          }}
        >
          {cellRealIndex.padStart(maxLen, "0")}
        </div>
      );
    }
    matrix.push(<div className="row">{row}</div>);
  }

  useEffect(() => {
    setColors(prev => {
      const next = [...prev];
      next[currentPixel] = c;
      return next;
    });
  }, [c]);

  function generateHeader() {
    const numberedLEDs = realIndexToPosition.filter(i => !isNaN(i));
    let header ='';


    console.log(realIndexToPosition);
    numberedLEDs
      .map((v, i) => ({ v, i }))
      .sort((a, b) => (a.v > b.v ? 1 : -1))
      .forEach(({ v, i }) => {
        const color = colors[v] ?? { rgb: { r: 0, g: 0, b: 0 } };
        header += `${colorOrder.split(" ").map(c => parseInt(color.rgb[c]/18)).join(",")}`;
		header += ",";
      });

    return header;
  }

  function openPreviewModal() {
    openModal(<div style={{whiteSpace: "pre"}}>{generateHeader()}</div>);
  }


  return (
    <div className="App">
      <h1>Creator UI</h1>
      <hr />
      <p>
        <b>Step 1</b>: Configure the size of the NeoPixel matrix.
      </p>
      <label>Rows</label>
      <br />
      <input
        type="number"
        min="0"
        palceholder="M"
        value={m}
        onChange={e => setM(Number(e.target.value))}
      />
      <br />
      <label>Columns</label>
      <br />
      <input
        type="number"
        min="0"
        palceholder="n"
        value={n}
        onChange={e => setN(Number(e.target.value))}
      />

      <p>
        <b>Step 2</b>: Select the NexPixels numbering.
      </p>
      <p>
        <small>
          For <i>Manual</i> numbering you have to click each NeoPixel in the
          order of the numbering (e.g. click first one first, second one second
          and so on), and the numbers will appear on them.
        </small>
      </p>
      <select
        name="numbering"
        value={countStrategy}
        onChange={e => setCountStrategy(e.target.value)}
      >
        <option value="column">Column</option>
        <option value="row">Row</option>
        <option value="manual">Manual</option>
      </select>
      <p>
        <b>Step 3</b>: Select the color component order.
      </p>
      <select
        name="numbering"
        value={colorOrder}
        onChange={e => setColorOrder(e.target.value)}
      >
        <option value="r g b">RGB</option>
      </select>
      <p>
        <b>Step 4</b>: Click on one NeoPixel to set its color. A color picker
        will Appear in this section.
      </p>
      {currentPixel !== null && (
        <SketchPicker
          color={c}
          onChange={c => {
            setC(c);
          }}
        />
      )}
      <p>
        <b>Step 5</b>: Get the code generated by clicking on button "Code" and send it through UART interface.
      </p>
      <button onClick={openPreviewModal}>Code</button>
      &nbsp;
      {n !== 0 && m !== 0 && (
        <>
          <h2>Generated NeoPixel preview.</h2>
          {matrix}
        </>
      )}
    </div>
  );
}

export default App;
