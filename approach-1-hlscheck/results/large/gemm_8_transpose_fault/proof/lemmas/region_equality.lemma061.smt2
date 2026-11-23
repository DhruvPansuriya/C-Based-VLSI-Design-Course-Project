; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_48 () (_ BitVec 32))
(assert
 (let ((?x39420 (bvmul arg0_14 arg1_6)))
(let ((?x54778 (bvmul (_ bv4294967295 32) ?x39420)))
(let ((?x64050 (bvmul arg0_14 arg1_48)))
(let ((?x66288 (bvadd ?x64050 ?x54778)))
(and (distinct ?x66288 (_ bv0 32)) true))))))
(check-sat)
