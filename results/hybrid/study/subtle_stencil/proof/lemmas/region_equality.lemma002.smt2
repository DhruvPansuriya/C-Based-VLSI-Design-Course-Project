; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x102194 (bvmul arg0_11 arg2_6)))
(let ((?x349499 (bvmul (_ bv4294967295 32) ?x102194)))
(let ((?x479396 (bvmul arg0_11 arg2_7)))
(let ((?x498205 (bvadd ?x479396 ?x349499)))
(and (distinct ?x498205 (_ bv0 32)) true))))))
(check-sat)
