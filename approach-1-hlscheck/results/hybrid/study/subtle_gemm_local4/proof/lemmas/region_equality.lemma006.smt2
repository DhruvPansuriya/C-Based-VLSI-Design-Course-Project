; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x22800 (bvmul arg0_5 arg1_6)))
(let ((?x11570 (bvmul (_ bv4294967295 32) ?x22800)))
(let ((?x356128 (bvmul arg0_5 arg1_7)))
(let ((?x11267 (bvadd ?x356128 ?x11570)))
(and (distinct ?x11267 (_ bv0 32)) true))))))
(check-sat)
